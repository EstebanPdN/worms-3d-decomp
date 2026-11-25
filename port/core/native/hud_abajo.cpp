// Datos de la partida para la pantalla de abajo de 3DS (v28, platform/3ds/ui_pages.cpp). Solo lectura: los mismos datos
// que usa el HUD del juego (estudio en /tmp/w3d-v28/research/hud.md, §1 y §5):
// - Relojes: TurnTimeRemaining, RoundTimeRemaining, HotSeatTimeRemaining (ms) y ClockDisplayMode (0 sin turno, 1 cuenta
//   atrás previa, 2 turno), como d32h_hud_clock_start_800a20cc.
// - Viento: Wind.Speed, Wind.MaxSpeed y Wind.Direction; el número del juego es speed*10/max + 0,5.
// - Equipos: vida de los gusanos vivos (+0xdc) sumada por equipo (+0xd5), como d29g_energy_bars_refresh_80065ce0; color
//   en el byte +0x3c del equipo (0 rojo, 1 azul, 2 verde, 3 amarillo, 4 cian, 5 rosa).
#include "native_game.h"
#include "hud_state.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

extern "C" {
w3d_u32 A800fc1f0(void *key, void *out, ...);
w3d_u32 A800fc230(void *key, void *out, ...);
w3d_u32 A800fc270(void *key, void *out, ...);
w3d_u32 A800fc6dc(void *worm);
w3d_u32 A800fc7f8(void *group);
int w3d_match_clock(unsigned *ms);
extern w3d_u32 A804b1884;

void w3d_gx_flush_camera();   // gx_metal.mm / gx_pica.cpp
// The GX batch must retain the camera that produced its vertices. Otherwise
// deferred world sprites are mistaken for HUD sprites after a camera switch.
int A80167898(w3d_u32 self, const float *matrix) {
    w3d_gx_flush_camera();
    memcpy(at<char>(self)+112,matrix,64);
    return 0;
}

// Render-state view matrix (+112; getter 80167908 / setter 80167898).
// The screen camera created by 80126e4c is at (0,0,500), with no rotation.
// Sprite batches bake that translation into vertices and use an identity view.
// Identify the camera itself: terrain can share its projection and depth.
int w3d_hud_screen_camera() {
    if(!A804b1884) return 0;
    const float *m=at<float>(A804b1884+112);
    return fabsf(m[0]-1)<.001f && fabsf(m[5]-1)<.001f && fabsf(m[10]-1)<.001f &&
        fabsf(m[12])<.001f && fabsf(m[13])<.001f &&
        (fabsf(m[14])<.01f || fabsf(m[14]+500)<.01f);
}

// Observers copy the original instruments after their own game-state gates and
// camera transforms. They never advance timers or modify simulation state.
static W3dHudDot dots[16];
static float meter_power, aim_angle, wind_yaw;
static int meter_visible, meter_enabled, aim_visible, initial_health[4];
static unsigned last_match_ms;
void w3d_hud_meter_observe(float p, int visible, int enabled) { meter_power=isfinite(p)?fmaxf(0,fminf(1,p)):0;meter_visible=visible;meter_enabled=enabled; }
void w3d_hud_aim_observe(float angle,int visible) { aim_angle=isfinite(angle)?angle:0;aim_visible=visible; }
void w3d_hud_wind_observe(float yaw) { wind_yaw=isfinite(yaw)?yaw:0; }
void w3d_hud_radar_observe(unsigned i,float x,float y,int visible) {
    if(i<16) dots[i]={isfinite(x)?x:0,isfinite(y)?y:0,visible};
}
unsigned char A8012f954(int weapon);

static int prop_int(const char *name, int def) { Ptr32<const char> key(name); int v = def; ((w3d_u32 (*)(void *, void *))A800fc1f0)(&key, &v); return v; }
static unsigned prop_uint(const char *name, unsigned def) { Ptr32<const char> key(name); w3d_u32 v = def; ((w3d_u32 (*)(void *, void *))A800fc230)(&key, &v); return v; }
static float prop_float(const char *name, float def) { Ptr32<const char> key(name); float v = def; ((w3d_u32 (*)(void *, void *))A800fc270)(&key, &v); return v; }

int w3d_hud_read(W3dHud *o) {
    memset(o, 0, sizeof *o);
    unsigned ms;
    if (!w3d_match_clock(&ms)) {
        memset(initial_health,0,sizeof initial_health);memset(dots,0,sizeof dots);
        meter_visible=meter_enabled=aim_visible=0;return 0;
    }
    if(ms+100<last_match_ms) memset(initial_health,0,sizeof initial_health);
    last_match_ms=ms;
    o->match_ms=ms; o->weapon=o->icon=-1;
    o->elevation=aim_angle; o->can_aim=aim_visible;
    o->power=meter_power;o->charging=meter_visible;o->charged=meter_enabled;o->wind_yaw=wind_yaw;
    memcpy(o->dots,dots,sizeof dots);
    o->in_match = 1;
    o->clock_mode = (int)prop_uint("ClockDisplayMode", 0);
    o->turn_ms = prop_int("TurnTimeRemaining", 0);
    o->round_ms = prop_int("RoundTimeRemaining", 0);
    o->hotseat_ms = prop_int("HotSeatTimeRemaining", 0);
    o->wind_speed = prop_float("Wind.Speed", 0);
    o->wind_max = prop_float("Wind.MaxSpeed", 1);
    o->wind_dir = prop_float("Wind.Direction", 0);
    o->wind_anim = prop_float("Wind.AnimScaler", 1);
    o->active_worm = prop_int("ActiveWormIndex", -1);
    o->active_team = -1;
    for (int i = 0; i < 16; i++) {
        w3d_u32 info = A800fc6dc(arg((w3d_u32)i));
        if (!info) continue;
        unsigned team = *at<uint8_t>(info + 0xd5);
        if (team > 3) continue;
        W3dHudTeam &t = o->teams[team];
        t.used = 1;
        o->worm_team[i]=(unsigned char)team;
        if (i == o->active_worm) {
            o->active_team = (int)team;
            o->health=*at<uint16_t>(info+0xaa);
            o->weapon=*at<int>(info+0x84);
            if((unsigned)o->weapon<64) {
                o->icon=A8012f954(o->weapon);
            }
        }
        if (*at<uint8_t>(info + 0xdc)) t.total += *at<uint16_t>(info + 0xaa);
    }
    for (int g = 0; g < 4; g++) {
        if (!o->teams[g].used) continue;
        w3d_u32 ginfo = A800fc7f8(arg((w3d_u32)g));
        if (!ginfo) continue;
        // TeamDataContainer's String at +28 (inventory_setup_800a57b0).
        Ptr32<const char> name=*at<Ptr32<const char>>(ginfo+28);
        if(name) snprintf(o->teams[g].name,sizeof o->teams[g].name,"%.63s",name.get());
        initial_health[g]=initial_health[g]>o->teams[g].total?initial_health[g]:o->teams[g].total;
        o->teams[g].maximum=initial_health[g];
        o->teams[g].colour = *at<uint8_t>(ginfo + 0x3c);
        o->teams[g].cpu = *at<w3d_u32>(ginfo + 0x34) == 1;   // como test_hooks.cpp (medido en Azahar, v18)
    }
    return 1;
}
}
