// Approved full-screen instrument panel, native 320x240. All values belong to
// the simulation; sprites/UV crops are the only animation here. No game timers.
#include "ui.h"
#include "hud_panel.h"
#include "hud_panel_assets.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// v39 (el dueño, 2026-11-10: «cuando aparezco en la partida, primero se me carga el HUD antiguo en la pantalla de abajo y
// después el nuevo; el antiguo no debería ni estar»). Hasta la v38 el panel solo contaba como activo con sus seis
// texturas ya subidas: en los primeros cuadros de la partida el juego bajaba su HUD original a la pantalla de abajo.
// Ahora el panel es el HUD de la partida desde el primer cuadro (el HUD original no baja nunca), sus texturas se suben
// durante la pantalla de carga (hud_panel_preload) y, si aún falta alguna, abajo va el azul del panel. Solo si una
// textura no se puede cargar vuelve el HUD original.
static bool panel_ready=false,panel_failed=false;
extern "C" int w3d_ui_panel_active() {
    return !panel_failed && w3d_fe_native_layout() && w3d_fe_game_mode()==7;
}
namespace ui { namespace {
using namespace hud35;
const Img *atlas,*font;
float unit(float v) {return isfinite(v)?fmaxf(0,fminf(1,v)):0;}
void piece(Region r,float x,float y,float w=0,float h=0,unsigned c=0xffffffff) {
    sprite(atlas,x,y,w>0?w:r.w,h>0?h:r.h,c,r.x,r.y,r.w,r.h);
}
void slice(Region r,float x,float y,float w,float h,int cx=9,int cy=9) {
    const float xs[]={x,x+cx,x+w-cx,x+w},ys[]={y,y+cy,y+h-cy,y+h};
    const float us[]={0.f,(float)cx,(float)(r.w-cx),(float)r.w},vs[]={0.f,(float)cy,(float)(r.h-cy),(float)r.h};
    for(int j=0;j<3;j++)for(int i=0;i<3;i++)
        sprite(atlas,xs[i],ys[j],xs[i+1]-xs[i],ys[j+1]-ys[j],0xffffffff,r.x+us[i],r.y+vs[j],us[i+1]-us[i],vs[j+1]-vs[j]);
}
const Glyph &glyph(unsigned c) {for(const Glyph &g:glyphs)if((unsigned)g.code==c)return g;return glyph('?');}
unsigned next(const char *&s) {unsigned c=(unsigned char)*s++;if(c<128)return c;
    if(c>=0xc2 && c<=0xdf && ((unsigned char)*s&0xc0)==0x80){unsigned b=(unsigned char)*s++;return ((c&31)<<6)|(b&63);}
    if(c>=0xe0 && c<=0xef && s[0] && s[1] && ((unsigned char)s[0]&0xc0)==0x80 && ((unsigned char)s[1]&0xc0)==0x80){unsigned b=(unsigned char)*s++,d=(unsigned char)*s++;return ((c&15)<<12)|((b&63)<<6)|(d&63);}return c;
}
float label_width(const char *s,float h){float w=0;while(*s)w+=glyph(next(s)).advance*h/16;return w;}
void label(const char *s,float x,float y,float h,bool center=false,float maxw=0) {
    float w=label_width(s,h);if(maxw>0 && w>maxw){h*=maxw/w;w=maxw;}if(center)x-=w/2;
    for(;*s;){unsigned c=next(s);const Glyph &g=glyph(c);float gw=g.advance*h/16;
        if(c!=' '){float kx=gw/g.sw,ky=h/g.sh;
            for(int shadow=1;shadow>=0;--shadow) sprite(font,x+(g.ox-2)*kx+(shadow?.7f:0),y+(g.oy-2)*ky+(shadow?1.f:0),(g.w+4)*kx,(g.h+4)*ky,shadow?0x000000b0:0xffffffff,g.x-2,g.y-2,g.w+4,g.h+4);
        }x+=gw;
    }
}
int digit_index(char c){return c==':'?11:c=='.'?10:c>='0'&&c<='9'?c-'0':-1;}
void number(const char *s,float x,float y,float h,bool yellow=false) {
    float lo=1e9f,hi=-1e9f,step=h*.63f;int i=0;
    for(const char *p=s;*p;p++,i++){int d=digit_index(*p);if(d<0)continue;lo=fminf(lo,i*step+ink[d][0]*h/32);hi=fmaxf(hi,i*step+ink[d][2]*h/32);}
    if(lo>hi)return;x-=(lo+hi)/2;i=0;Region r=yellow?digits_yellow:digits_white;
    for(;*s;s++,i++){int d=digit_index(*s);if(d>=0)sprite(atlas,x+i*step,y,h,h,0xffffffff,r.x+(d%4)*32,r.y+(d/4)*32,32,32);}
}
const Region capsules[]={team_red,team_blue,team_green,team_yellow,team_cyan,team_pink};
constexpr int team_row_y(int row) { return 8 + row * (team_red.h + 2); }
const Region fills[]={health_red,health_blue,health_green,health_yellow,health_cyan,health_pink};
const Region blips[]={blip_red,blip_blue,blip_green,blip_yellow,blip_cyan,blip_pink};
}
// Pide las texturas del panel (se suben de cuatro en cuatro por cuadro). true cuando están todas.
bool hud_panel_preload() {
    const Img *all[6]={img("hud35_ui.w3ui",0),img("hud35_font.w3ui",1),img("hud35_face.w3ui",2),img("hud35_wind.w3ui",1),img("hud35_arrow.w3ui",1),img("weapons_hd.w3ui",1)};
    bool ready=true,failed=false;
    for(const Img *i:all){ready=ready && i->tex>=0;failed=failed || i->failed;}
    panel_ready=ready;panel_failed=failed;
    return ready;
}
bool hud_panel(const W3dHud &h) {
    atlas=img("hud35_ui.w3ui",0);font=img("hud35_font.w3ui",1);
    const Img *face=img("hud35_face.w3ui",2),*wind=img("hud35_wind.w3ui",1),*arrow=img("hud35_arrow.w3ui",1);
    const Img *weapons=img("weapons_hd.w3ui",1);
    if(!hud_panel_preload())return false;
    sprite(face,0,0,320,240);
    constexpr int team_slots = sizeof(h.teams) / sizeof(h.teams[0]);
    int count=0,order[team_slots];for(int g=0;g<team_slots;g++)if(h.teams[g].used)order[count++]=g;
    for(int row=0;row<count;row++) {
        int g=order[row];const W3dHudTeam &t=h.teams[g];unsigned col=(unsigned)t.colour%6;
        const int y=team_row_y(row),cy=y+team_red.h/2;
        piece(capsules[col],8,y);
        piece(health_track,49,cy-1);
        float ratio=t.maximum>0?unit((float)t.total/t.maximum):0;
        if(ratio>0) {Region r=fills[col];sprite(atlas,50,cy,96*ratio,9,0xffffffff,r.x,r.y,96*ratio,9);}
        piece(t.cpu?portrait_cpu:portrait_human,15,cy-12,24,24);
        if(g==h.active_team)piece(active_team,9,cy-6);
    }
    // El brillo de la cápsula queda abajo al invertirla, como el borde de un hueco.
    for(int row=count;row<team_slots;row++) {
        sprite(atlas,8,team_row_y(row),team_blue.w,team_blue.h,0x78664ecc,
               team_blue.x,team_blue.y+team_blue.h,team_blue.w,-team_blue.h);
    }
    slice(radar_bezel,166,7,146,138);piece(radar_glass,175,12);
    for(int i=0;i<16;i++)if(h.dots[i].visible && h.worm_team[i]<4) {
        float x=239+fmaxf(-1,fminf(1,h.dots[i].x))*57,y=76+fmaxf(-1,fminf(1,h.dots[i].y))*57;
        if(i==h.active_worm)piece(radar_active,x-4.5f,y-4.5f,9,9,0xffffffb0);
        piece(blips[(unsigned)h.teams[h.worm_team[i]].colour%6],x-2.5f,y-2.5f);
    }
    slice(weapon_bay,8,148,68,86);slice(firing_bay,80,148,88,86);slice(clock_bay,172,148,62,86);slice(wind_bay,238,148,74,86);
    // Icons 0..63 use the game's own weapon->icon mapping (including tools).
    // v39: every weapon comes from the same atlas (weapons_hd, the v4 set redrawn in the original style). The bazooka,
    // grenade and shotgun used to be separate pieces of the panel atlas, in the older rendered look. Square and one
    // texel inside the cell: no stretch, no bleed from the neighbour.
    {
        int icon=h.icon>=0 && h.icon<63?h.icon:h.weapon==0?0:h.weapon==1?1:h.weapon==8?8:-1;
        if(icon>=0) sprite(weapons,19,155,46,46,0xffffffff,(icon%8)*64+1,(icon/8)*64+1,62,62);
    }
    piece(worm_health,15,208);
    char s[40];snprintf(s,sizeof s,"%d",h.health);number(s,51,210,14);
    piece(elevation_scale,85,155,60,60,h.can_aim?0xffffffff:0xffffff60);
    piece(power_track,148,156,14,58,h.charged?0xffffffff:0xffffff60);
    if(h.charging && h.charged && h.power>0){float height=50*unit(h.power);Region r=power_fill;sprite(atlas,151,210-height,8,height,0xffffffff,r.x,r.y+50-height,8,height);}
    int turn=(h.clock_mode==1?h.hotseat_ms:h.turn_ms);turn=turn>0?(turn+999)/1000:0;
    snprintf(s,sizeof s,"%02d",turn);number(s,202,161,turn>99?24:31,true);
    int seconds=h.round_ms>0?h.round_ms/1000:0;snprintf(s,sizeof s,"%d:%02d",seconds/60,seconds%60);number(s,202,209,12);
    float speed=h.wind_max>0?unit(h.wind_speed/h.wind_max):0;
    { static float force=-2; if(force<-1){const char *e=getenv("W3D_HUD_WIND");force=e?unit((float)atof(e)):-1;} if(force>=0)speed=force; }   // pruebas: la fuerza del viento que enseña el panel
    // La fuerza en números (de 00 a 10, como el juego: fuerza*10/máximo + 0,5). v43: la v42 la dejó comentada sin querer.
    snprintf(s,sizeof s,"%02d",(int)(speed*10+.5f));number(s,275,204,23,true);
    if(h.can_aim)piece(degree_mark,123,217,4,4);
    // Group labels on the padded font atlas; no neighboring glyph bleed.
    for(int row=0;row<count;row++) {const W3dHudTeam &t=h.teams[order[row]];label(*t.name?game_text(t.name):(t.cpu?"CPU":"Human"),51,team_row_y(row)+team_red.h/2-13,11.5f,false,99);}
    static const char *const turn_labels[]={"TURN","TOUR","ZUG","TURNO","TURNO"};
    label(turn_labels[(unsigned)lang()%5],202,192.5f,11,true,56);   // v41: mucho más grande (el dueño); antes 6,5
    if(h.can_aim)snprintf(s,sizeof s,"%d",(int)roundf(h.elevation*57.2957795f));else snprintf(s,sizeof s,"--");label(s,113,218,10,true);
    if(h.can_aim)sprite_rot(arrow,115,185,64,64,h.elevation);
    // The engine supplies camera-relative yaw; compensate the sprite rig camera azimuth atan2(7,10) so atlas front
    // agrees with the original HUD camera.
    // v42: the original yaw sways (the "wobble" of 0x801303d4): with 16 bins it flipped back and forth at a bin edge.
    // The bin now changes only when the yaw is 0.65 of a bin away from the current one.
    float yaw=fmodf(h.wind_yaw+0.61072596f,6.2831853f);if(yaw<0)yaw+=6.2831853f;
    static int dir=-1;
    {const float bin=yaw*16/6.2831853f;
     float off=bin-(dir<0?0:dir);off=fmodf(off+24,16)-8;
     if(dir<0 || fabsf(off)>.65f)dir=(int)floorf(bin+.5f)%16;}
    // v42 rotor (the owner: v41 "jumped in strange ways"): the head has three blades, so it repeats every 120 degrees;
    // the old sheet held a quarter turn and jumped 30 degrees back on every wrap. Twelve positions across 120 degrees
    // (tools/build3ds/ui/viento12_w3ui.py: even ones in hud35_wind, odd ones in hud35_wind2), no blending. Speed as in
    // the original (0x80130ed8): the clip Wind_AnimSource1 (one turn in 1.25 s) plays at 1/(ratio*Wind.AnimScaler) of
    // its time, so ratio*AnimScaler/1.25 turns per second; no wind, no spin. It runs on the match clock, so pausing
    // stops it. Without hud35_wind2 (no VRAM) it keeps the six even positions.
    const Img *wind2=img("hud35_wind2.w3ui",1);
    const bool twelve=wind2->tex>=0;
    static float thirds=0;static unsigned last_ms=0;
    {float dt=(float)(h.match_ms-last_ms)*.001f;if(h.match_ms<last_ms || dt>.25f)dt=0;last_ms=h.match_ms;
     const float turns=speed*(h.wind_anim>0?h.wind_anim:1)/1.25f;
     thirds=fmodf(thirds+dt*turns*3,1.f);}
    int phase=(int)(thirds*12)%12;if(!twelve)phase&=~1;
    {const int cell=dir*6+phase/2;
     sprite((phase&1)?wind2:wind,250,155,48,48,0xffffffff,(cell%10)*50+1,(cell/10)*50+1,48,48);}
    static unsigned last_log=~0u;const char *debug=getenv("W3D_HUD35_LOG");
    if(debug && (last_log==~0u || h.match_ms-last_log>=1000)) {
        last_log=h.match_ms;fprintf(stderr,"[hud35] ms=%u teams=%d worm=%d team=%d hp=%d weapon=%d icon=%d aim=%d elev=%.3f charged=%d charging=%d power=%.3f wind=%.3f anim=%.3f yaw=%.3f rows=",h.match_ms,count,h.active_worm,h.active_team,h.health,h.weapon,h.icon,h.can_aim,h.elevation,h.charged,h.charging,h.power,h.wind_speed,h.wind_anim,h.wind_yaw);
        for(int g=0;g<4;g++)if(h.teams[g].used)fprintf(stderr," %s:%d/%d",h.teams[g].name,h.teams[g].total,h.teams[g].maximum);fprintf(stderr,"\n");
    }
    return true;
}
}
