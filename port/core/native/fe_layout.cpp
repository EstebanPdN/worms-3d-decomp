// Native FE layout: transform the control's parent, keeping the original animated
// child, material, typography and interaction controller intact.
#include "native_game.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
extern "C" {
void A8015adf4(GameString *, void *, w3d_u32);
void A8020bb54(GameString *, const char *);
void A80341588(GameString *);
const char *w3d_fe_layout_menu(void);
const char *w3d_fe_prop_str(const char *);
int w3d_fe_game_mode(void);
int w3d_fe_popup_depth(void);
const char *w3d_fe_last_popup(void);
const char *w3d_test_fe_menu(void);
void w3d_dbg(const char *, ...);
int w3d_ui_carousel_layout(const char *,const char *,float *,float *,float *);
int w3d_ui_weapon_layout(const char *,float *,float *,float *);
void w3d_fe_apply_layout(void *);
int w3d_fe_place_screen(const char *,const char *);
int w3d_ui_outfit_open(void);   // platform/ui/ui_pages.cpp: Crear equipo enseña su página Outfit
}
namespace {
struct Vec { float x,y,z; };
struct Config { char pad[20]; Vec size, pos; Ptr32<const char> strings[18]; };
struct Panel { char pad[12]; Ptr32<Config> cfg; char gap[68]; Ptr32<void> base,frame; };
// x, y, w, h: lower-screen pixels. zoom, dx, dy: placement (FE units = zoom*original+d).
// born/gone: when the control was created and when its menu was left (0 while it is current); order: its place
// among the controls its menu created together (the pop-in is staggered by it).
struct Entry { void *panel; char menu[64], name[64]; float x,y,w,h; bool touch, bottom, visible; int depth; float zoom,dx,dy; double seen, born, gone; int order; bool linked; };
double seconds() { struct timespec ts; clock_gettime(CLOCK_MONOTONIC,&ts); return ts.tv_sec+ts.tv_nsec*1e-9; }
Entry entries[1024]; unsigned entry_count;
struct WeaponCell { int icon=-1, locked=0; };
WeaponCell weapon_cells[54];
void load(const char *name, Ptr32<void> *out) {
    GameString s; A8020bb54(&s,name); A8015adf4(&s,out,255); A80341588(&s);
}
void move(void *node, Vec v) { call_virtual<void>(node,76,&v,0); }
void scale(void *node, Vec v) { call_virtual<void>(node,84,&v,0); }
bool dual() {
#if defined(__3DS__)
    // Dos pantallas también en 3DS (gx_pica.cpp lo dibuja como gx_metal.mm). W3D_NO_DUAL=1 (debug.ini): el menú original.
    static const bool on = getenv("W3D_NO_DUAL") == nullptr;
    return on;
#else
    return getenv("W3D_DUAL") != nullptr;
#endif
}
}
namespace { bool placed_menu(const char *menu); }
extern "C" void A802b192c(Ptr32<Panel> self) {
    load("NULL", &self->base);
    Config *c=self->cfg.get();
    auto s=[&](int off){ return *(Ptr32<const char> *)((char *)c+off); };
    bool animated=false;
    for (int off=92; off<=104; off+=4) if (s(off) && *s(off)) animated=true;
    load(animated?"Frontend.Anim":"NULL", &self->frame);
    move(self->frame.get(),c->pos);
    scale(self->frame.get(),{1,1,1});
    Vec zero{0,0,0};
    call_virtual<void>(self->frame.get(),80,&zero,0);
    // Original attachment: the control hangs from the animated locator, which plays the
    // game's IN_*/OUT_* clips. With two screens no menu keeps it: the clips' 4:3 flight paths
    // cross both screens, and in the menus redone with kPlaces each piece (a panel's frame,
    // its rows, its buttons) zoomed around its own centre, so the panels came apart while
    // Multiplayer opened (owner, 2026-11-06). Controls are fixed and pop in/out instead
    // (transition()); placed groups grow as one piece from their anchor.
    const bool locator=animated && !dual();
    call_virtual<void>(self->frame.get(),92,self->base.get(),locator?"locator1":nullptr);
    move(self->base.get(),zero);
    call_virtual<void>(self->base.get(),80,&zero,1);
    scale(self->base.get(),{1,1,1});
    if (!dual()) return;
    const char *m=w3d_fe_layout_menu(), *name=s(88)?s(88).get():"";
    // Land Select: the theme combo as wide as the landscape list (owner's sketch). The combo builds its box from the
    // configured size, so its corners keep their shape (no scaling stretch).
    if(!strcmp(m,"FE.LandSelect") && !strcmp(name,"Types") && c->size.x<130) c->size.x=130;
    // Beta 0.1: ambas columnas del resultado comparten caja y línea superior.
    // Cambiar la configuración antes de construir el marco conserva sus esquinas.
    if(!strcmp(m,"FE.PostChallenge")) {
        if(!strcmp(name,"Result Frame") || !strcmp(name,"All Times Frame")) {
            c->size.x=130; c->size.y=161; c->pos.y=40;
        } else if(!strcmp(name,"Team Name")) {c->pos.x=-144;c->pos.y=164;}
        else if(!strcmp(name,"Trophy")) c->pos.y=40;
        move(self->frame.get(),c->pos);
    }
    if(!strcmp(m,"FE.WeaponPanel") && !strcmp(name,"WeaponPanelBorder"))
        for(auto &cell:weapon_cells) cell=WeaponCell{};
    if(getenv("W3D_LAYOUT_LOG")) w3d_dbg("[layout] %s / %s pos %.2f %.2f %.2f size %.2f %.2f %.2f vt %08x\n",m,name,c->pos.x,c->pos.y,c->pos.z,c->size.x,c->size.y,c->size.z,(unsigned)*(const w3d_u32 *)((const char *)self.get()-28));
    unsigned i=0; while(i<entry_count && entries[i].panel!=self.get()) ++i;
    if(i==entry_count && entry_count<1024) ++entry_count;
    if(i<1024) {
        Entry &e=entries[i]; const double now=seconds();
        e.panel=self.get(); snprintf(e.menu,64,"%s",m); snprintf(e.name,64,"%s",name); e.touch=false;
        e.born=now; e.gone=0; e.order=0;
        // Navigable (has neighbours) as the game made it, before any link is cut below: it stays touchable.
        e.linked=false;
        for(int off=72;off<=84;off+=4) { auto v=*(Ptr32<const char> *)((char *)c+off); if(v && *v) e.linked=true; }
        for(unsigned j=0;j<entry_count;++j) if(j!=i && now-entries[j].born<.3 && !strcmp(entries[j].menu,m)) ++e.order;
    }
    // Multiplayer (owner, 2026-11-06): the pad only moves among the controls of the upper screen; the lower ones are
    // for the stylus. Links (config +72..+84, names of the neighbours) into the lower screen are cut, and the lower
    // controls lose theirs (the UI sends the pad back up from there: w3d_fe_place_screen). They are the game's
    // reference-counted strings and the config is the menu data itself: a cut link gets the game's empty string, with
    // its count. Writing NULL there crashed the next match load, when MenuTwk.xom is read again and its strings are
    // released (0x80341588 on 0x00000000 - 6; seen 2026-11-07 with a match started from Multiplayer).
    if(!strcmp(m,"FE.MultiplayerMenu"))
        if(const int here=w3d_fe_place_screen(m,name); here>=0) {
            static GameString empty;
            if(!empty.text) A8020bb54(&empty,"");
            for(int off=72;off<=84;off+=4) {
                auto &v=*(Ptr32<const char> *)((char *)c+off);
                if(!v || !*v) continue;
                if(here==1 || w3d_fe_place_screen(m,v.get())==1) ((GameString *)&v)->assign(empty);
            }
        }
    w3d_fe_apply_layout(self.get());
}

extern "C" int w3d_fe_native_layout(void) { return dual(); }
// d32e_frustum_test_sphere_801a9cbc: con dos pantallas, en los menús (modo 6) el lienzo sigue por debajo de la pantalla
// de arriba, así que la cámara del FE no descarta nada por su vista de 4:3 (que solo cubre la pantalla de arriba).
extern "C" int w3d_cull_tall(void) { return dual() && w3d_fe_game_mode()==6; }
namespace {
// Two-screen placement of the game's own controls. Members of a group share an anchor
// (original FE units) and a zoom, so the original arrangement, borders and proportions
// stay intact; (sx, sy) shifts a member inside its group before scaling. screen 0 is the
// upper screen (400x240), 1 the lower one (320x240); the target is in that screen's FE
// units (0.475 px per unit, centre origin, y up).
// wx: extra horizontal stretch of a flat piece (a frame), 0 = none.
struct Place { const char *menu, *name; float ax, ay, zoom, tx, ty; int screen; float sx, sy, wx; };
const Place kPlaces[] = {
    // Multiplayer: game settings, preview and help above; the Teams panel and actions below.
    {"FE.MultiplayerMenu", "Title",            -150, 192, 1.00f, -266, 205, 0, 0, 0},
    {"FE.MultiplayerMenu", "Scheme Frame",      145,  98, 1.40f, -211,  15, 0, 0, 0},
    {"FE.MultiplayerMenu", "Scheme",            145,  98, 1.40f, -211,  15, 0, 0, 0},
    {"FE.MultiplayerMenu", "Add Scheme",        145,  98, 1.40f, -211,  15, 0, 0, 0},
    // The two "?" buttons move below, so the six quick settings are centred in their frame.
    {"FE.MultiplayerMenu", "TeleportIn",        145,  98, 1.40f, -211,  15, 0, 37, 0},
    {"FE.MultiplayerMenu", "Toggle",            145,  98, 1.40f, -211,  15, 0, 37, 0},
    {"FE.MultiplayerMenu", "Wins",              145,  98, 1.40f, -211,  15, 0, 37, 0},
    {"FE.MultiplayerMenu", "Health",            145,  98, 1.40f, -211,  15, 0, 37, 0},
    {"FE.MultiplayerMenu", "RoundTime",         145,  98, 1.40f, -211,  15, 0, 37, 0},
    {"FE.MultiplayerMenu", "TurnTime",          145,  98, 1.40f, -211,  15, 0, 37, 0},
    {"FE.MultiplayerMenu", "LAND FRAME",         87, -73, 2.40f,  216,  15, 0, 0, 0},
    {"FE.MultiplayerMenu", "Landscape",          87, -73, 2.40f,  216,  15, 0, 0, 0},
    {"FE.MultiplayerMenu", "ToolTip Frame",       0,-180, 1.25f,    0,-201, 0, 0, 0},
    {"FE.MultiplayerMenu", "ToolTips",            0,-180, 1.25f,    0,-201, 0, 0, 0},
    // Lower screen (pixels): Teams panel x 10-173, y 25-181, centred in the space above Back and Start;
    // the four ring buttons in a 2x2 grid with their names below (ui_pages.cpp), Back and Start in the corners.
    {"FE.MultiplayerMenu", "Team Frame",       -140,   4, 1.25f, -144.5f, 36.2f, 1, 0, 0},
    {"FE.MultiplayerMenu", "Barracks",         -140,   4, 1.25f, -144.5f, 36.2f, 1, 0, 0},
    {"FE.MultiplayerMenu", "Create Team",      -140,   4, 1.25f, -144.5f, 36.2f, 1, 0, 0},
    {"FE.MultiplayerMenu", "Team Roster",      -140,   4, 1.25f, -144.5f, 36.2f, 1, 0, 0},
    {"FE.MultiplayerMenu", "Landscape Button",  248, -95, 1.25f,  111.6f, 122.1f, 1, 0, 0},
    {"FE.MultiplayerMenu", "WORMPOT",           205, -52, 1.25f,  250.5f, 122.1f, 1, 0, 0},
    {"FE.MultiplayerMenu", "Game Settings",     246,  36, 1.45f,  111.6f, -25.3f, 1, 0, 0},
    {"FE.MultiplayerMenu", "Weapon Options",    246,  92, 1.45f,  250.5f, -25.3f, 1, 0, 0},
    {"FE.MultiplayerMenu", "Back",             -256,-178, 1.10f, -275.8f,-202.1f, 1, 0, 0},
    {"FE.MultiplayerMenu", "Start",             256,-178, 1.10f,  275.8f,-202.1f, 1, 0, 0},
    // Land Select (owner's second sketch, 2026-11-06). Above: the menu title and the 3D preview of the map, a little
    // smaller so it does not cover the title (its frame and the wide picture of a predefined map are drawn by the UI,
    // ui_pages.cpp). Below: landscape list | theme; the seven ring settings 4 + 3 on the big panel; Cancel, a tray with
    // code, generate, time of day and the indestructible toggle, and Accept along the bottom.
    {"FE.LandSelect", "Title",            -150, 192, 1.00f, -266,   205,   0, 0, 0},
    {"FE.LandSelect", "Landscape",        -150, -24, 2.20f,    0, -29.5f, 0, 0, 0},
    {"FE.LandSelect", "User Landscapes",  -150, 119, 1.15f, -160.0f, 189.5f, 1, 0, 0},
    {"FE.LandSelect", "Types",             110, 119, 1.15f,  157.9f, 189.5f, 1, 0, 0},
    {"FE.LandSelect", "Amount",             57, -24, 1.10f, -202.1f,  71.6f, 1, 0, 0},
    {"FE.LandSelect", "Size",              241, -24, 1.10f,  -67.4f,  71.6f, 1, 0, 0},
    {"FE.LandSelect", "Height",            195, -95, 1.10f,   63.2f,  71.6f, 1, 0, 0},
    {"FE.LandSelect", "Space",             103, -95, 1.10f,  197.9f,  71.6f, 1, 0, 0},
    {"FE.LandSelect", "Bridges",           149, -24, 1.10f, -136.8f, -37.9f, 1, 0, 0},
    {"FE.LandSelect", "Small Objects",     103,  47, 1.10f,      0,  -37.9f, 1, 0, 0},
    {"FE.LandSelect", "Objects",           195,  47, 1.10f,  134.7f, -37.9f, 1, 0, 0},
    {"FE.LandSelect", "Cancel",           -256,-178, 1.00f, -286.3f,-172.6f, 1, 0, 0},
    {"FE.LandSelect", "Code",              110, 180, 0.95f, -122.1f,-169.4f, 1, 0, 0},
    {"FE.LandSelect", "Generate",          250, 180, 1.05f,   18.9f,-168.4f, 1, 0, 0},
    {"FE.LandSelect", "Time",              250, 119, 1.00f,  101.1f,-168.4f, 1, 0, 0},
    {"FE.LandSelect", "Indest",            -40,-111, 0.90f,  181.1f,-168.4f, 1, 0, 0},
    {"FE.LandSelect", "Accept",            256,-178, 1.00f,  286.3f,-172.6f, 1, 0, 0},
    // Create / edit team (owner, 2026-11-07): the title above, where the UI draws the 3D worm and the roster
    // (ui_pages.cpp); below, the original arrangement 12 % bigger and without its title, Cancel and Accept in the corners
    // and room between them for the Outfit button. The help line goes (the owner's menus have none below).
    {"FE.Create Edit Team", "Title",         -150, 192, 1.00f, -266,   205,   0, 0, 0},
#define W3D_CET(n) {"FE.Create Edit Team", n, 7, 50, 1.12f, 0, 40, 1, 0, 0}
    W3D_CET("Barracks"), W3D_CET("Add"), W3D_CET("Speech"), W3D_CET("Play Speech"), W3D_CET("Flag"), W3D_CET("Tombstone"),
    W3D_CET("Delete"), W3D_CET("Special Weapon2"), W3D_CET("Team Frame"),
    W3D_CET("Worm Name 1"), W3D_CET("Worm Name 2"), W3D_CET("Worm Name 3"), W3D_CET("Worm Name 4"), W3D_CET("Worm Name 5"), W3D_CET("Worm Name 6"),
    W3D_CET("Worm Random 1"), W3D_CET("Worm Random 2"), W3D_CET("Worm Random 3"), W3D_CET("Worm Random 4"), W3D_CET("Worm Random 5"), W3D_CET("Worm Random 6"),
#undef W3D_CET
    {"FE.Create Edit Team", "Cancel",       -256,-178, 1.10f, -275.8f,-202.1f, 1, 0, 0},
    {"FE.Create Edit Team", "Accept",        256,-178, 1.10f,  275.8f,-202.1f, 1, 0, 0},
};
// Menus without a page of their own (owner, 2026-11-07: "the title must not be repeated on both screens"): their title
// goes to the upper screen, in the same place as in the placed menus, and the rest stays below; these ones, bigger and
// centred now that the title is gone (zoom, and the original point that goes to the centre of the lower screen).
struct Generic { const char *menu; float zoom, cx, cy; };
const Generic kGeneric[] = {{"FE.GameSettings", 1.10f, 0, -9}, {"FE.GameSettings2", 1.10f, 0, -9}};
const Generic *find_generic(const char *menu) {
    for (const Generic &g : kGeneric) if (!strcmp(g.menu, menu)) return &g;
    return nullptr;
}
// Centre of the lower screen on the tall canvas, in FE units: the lower half starts where the upper one ends
// (120 px / 0.475 below the centre), so its centre is two half-heights down. (-480 drew 12 px too high.)
const float kLower = 2 * 120 / .475f;
// Menu change for controls without the original locator: the control pops in when its menu
// opens (ease-out with a small overshoot, staggered) and shrinks away as soon as its menu is
// left, instead of standing still while the FE waits for the old menu's OUT clip. Returns the
// scale factor (0: not shown). While a popup is open nothing leaves; a closed popup's controls do.
float transition(Entry &e) {
    const double now=seconds();
    const char *cur=w3d_test_fe_menu();
    const char *pop=w3d_fe_popup_depth()>0?w3d_fe_last_popup():nullptr;
    const bool here=!*e.menu || !cur || pop || !strcmp(cur,e.menu);
    if(here) e.gone=0; else if(!e.gone) e.gone=now;
    if(e.gone) { const float t=(float)(now-e.gone)/.14f; return t>=1?0:1-t*t; }
    // The new menu waits (0.1 s) while the old one shrinks away, so the two never overlap.
    const float t=(float)(now-e.born-.1-.025*(e.order<6?e.order:6))/.28f;
    if(t<=0) return 0;
    if(t>=1) return 1;
    const float c=1.4f, u=t-1;
    return 1+(c+1)*u*u*u+c*u*u;
}
const Place *find_place(const char *menu, const char *name) {
    for (const Place &p : kPlaces) if (!strcmp(p.menu, menu) && !strcmp(p.name, name)) return &p;
    return nullptr;
}
bool placed_menu(const char *menu) {
    for (const Place &p : kPlaces) if (!strcmp(p.menu, menu)) return true;
    return false;
}
// The team window (FE.PopTeamAdjust) is open over Multiplayer (the FE may also report it as the current menu).
bool team_window() {
    const char *p=w3d_fe_popup_depth()>0?w3d_fe_last_popup():nullptr, *cur=w3d_test_fe_menu();
    return (p && !strcmp(p,"FE.PopTeamAdjust")) || (cur && !strcmp(cur,"FE.PopTeamAdjust"));
}
}
extern "C" char A8041c790[];   // ComboControl (ver w3d_fe_open_combo)
extern "C" void w3d_fe_apply_layout(void *ptr) {
    if (!dual() || (w3d_fe_game_mode()!=6 && w3d_fe_game_mode()!=7)) return;
    Panel *p=(Panel *)ptr;
    unsigned i=0; while(i<entry_count && entries[i].panel!=ptr) ++i;
    if(i==entry_count || !p->base) return;
    Entry &e=entries[i]; const char *m=e.menu, *n=e.name;
    e.seen=seconds(); e.visible=false;
    if(!strcmp(m,"FE.WeaponPanel")) {
        int col,row,icon;
        auto sprite=*(Ptr32<const char> *)((char *)p->cfg.get()+136);
        auto action=*(Ptr32<const char> *)((char *)p->cfg.get()+128);
        if(sscanf(n,"WeaponPanel-%d,%d",&col,&row)==2 && col>=0 && col<6 && row>=0 && row<9) {
            WeaponCell &cell=weapon_cells[row*6+col];
            cell.icon=action && *action && sprite && sscanf(sprite.get(),"FE.WeaponIcons:%d",&icon)==1?icon:-1;
            cell.locked=(((unsigned char *)p->cfg.get())[8]&4)!=0;
        }
    }
    if(!*m) m="FE.MainMenu";
    // The new-team window (FE.NewTeam) is a page of the UI too: it goes straight to the game's keyboard (ui_pages.cpp).
    const bool custom=!strcmp(m,"FE.MainMenu") || !strcmp(m,"FE.SinglePlayerMenu") || !strcmp(m,"FE.Options") || !strcmp(m,"FE.LanguageSelect") || !strcmp(m,"FE.PopTeamAdjust") || !strcmp(m,"FE.NewTeam") || !strcmp(m,"FE.PauseMenu") || !strcmp(m,"FE.TutorialMenu") || !strcmp(m,"FE.CampaignMenu") || !strcmp(m,"FE.Challenge Menu") || !strcmp(m,"Game.BriefDialog");
    bool hidden=custom;
    const bool match=w3d_fe_game_mode()==7;
    float zoom=1, dy=-480, dx=0;
    int screen=-1;
    if(const Place *pl=find_place(m,n)) {
        hidden=false;zoom=pl->zoom;screen=pl->screen;
        dx=pl->tx+zoom*(pl->sx-pl->ax);
        dy=pl->ty+zoom*(pl->sy-pl->ay)-(pl->screen?kLower:0);
    } else if(!strcmp(m,"FE.LandSelect") && (!strcmp(n,"ToolTips") || !strcmp(n,"ToolTip Frame") || !strcmp(n,"Landscape Frame"))) {
        hidden=true;   // the owner's sketch has no help line; the preview frame is drawn in proportion by the UI
    } else if(placed_menu(m)) {
        hidden=true;   // a placed menu shows only what it places (and what its UI page draws)
        if(getenv("W3D_LAYOUT_LOG")) w3d_dbg("[layout] %s / %s sin sitio\n",m,n);
    } else if(!strcmp(m,"FE.Wormpot") && !strcmp(n,"New.WormPot")) {
        // The machine is a 3D scene with native culling, not a flat FE button.
        // Keep its original camera-space position; the touch controls live below.
        hidden=false;zoom=.78f;dy=20;
    } else if(!strcmp(m,"FE.Wormapedia")) {
        hidden=!strcmp(n,"ToolTips") || !strcmp(n,"ToolTip Frame");
        if(!strcmp(n,"Previous") || !strcmp(n,"Next") || !strcmp(n,"Credits") || !strcmp(n,"Unlocked") || !strcmp(n,"Back")) {
            Config *c=p->cfg.get();
            float x=!strcmp(n,"Previous")?-160:!strcmp(n,"Next")?160:!strcmp(n,"Credits")?-80:!strcmp(n,"Unlocked")?80:-256;
            float y=!strcmp(n,"Back")?-178:(!strcmp(n,"Previous") || !strcmp(n,"Next"))?35:-80;
            dx=x-c->pos.x;dy=-480+y-c->pos.y;
        } else {dy=-20;zoom=1.25f;}
    } else if(!strcmp(m,"FE.SoundOptions")) {
        // Keep the original equalizers on the upper screen; the touch sliders
        // below edit these same audio properties.
        hidden=!strcmp(n,"ToolTips") || !strcmp(n,"ToolTip Frame") || !strcmp(n,"Cancel") || !strcmp(n,"Title");
        zoom=1.25f; dy=-15;
    } else if(!strncmp(m,"FE.PostTutorial",15) || !strncmp(m,"FE.PostCampaign",15) || !strncmp(m,"FE.PostChallenge",16)) {
        // Keep the original result table, unlock art and medals above. Native
        // action buttons remain below, with the help text drawn by the UI.
        const Config *cf=p->cfg.get();
        hidden=!strcmp(n,"ToolTips") || !strcmp(n,"ToolTip Frame");
        screen=0; zoom=1.85f; dy=-103.5f;
        // Success pages have different native frames: Tutorial is taller,
        // Campaign wider, and Challenge includes two complete results tables.
        if(!strcmp(m,"FE.PostTutorial")) {zoom=1.55f;dy=-93.6f;}
        else if(!strcmp(m,"FE.PostCampaign")) {zoom=1.8f;dy=-91.f;}
        else if(!strcmp(m,"FE.PostChallenge")) {zoom=1.25f;dy=-92.1f;}
        if(!strcmp(n,"Title")) {zoom=1;dx=-266-cf->pos.x;dy=205-cf->pos.y;}
        else if(e.linked) {
            screen=1;zoom=1.4f;
            const float x=cf->pos.x<-50?70:cf->pos.x>50?250:160;
            dx=(x-160)/.475f-zoom*cf->pos.x;
            dy=-kLower+(120-204)/.475f-zoom*cf->pos.y;
        }
    } else if(!custom) {
        hidden=!strcmp(n,"ToolTips") || !strcmp(n,"ToolTip Frame");
        const Config *cf=p->cfg.get();
        if(!strcmp(n,"Title")) { screen=0; zoom=1; dx=-266-cf->pos.x; dy=205-cf->pos.y; }
        else if(const Generic *g=find_generic(m)) { zoom=g->zoom; dx=-zoom*g->cx; dy=-zoom*g->cy-kLower; }
    }
    if(strstr(m,"Confirm") || !strcmp(m,"FE.LeaveOptions") || !strcmp(m,"FE.LeaveMultiplayer")) {
        zoom=1.6f;
        if(!match && !e.linked && !strcmp(n,"Quit")) hidden=true; // Question is shown once, above.
    }
    float cx,cy,diameter;
    int carousel=!strcmp(m,"FE.WeaponPanel") ? w3d_ui_weapon_layout(n,&cx,&cy,&diameter) : w3d_ui_carousel_layout(m,n,&cx,&cy,&diameter);
    if(carousel==1) {
        Config *c=p->cfg.get();
        hidden=false;zoom=diameter/(fabsf(c->size.x)*.95f);
        dx=(cx-160)/.475f-c->pos.x*zoom;
        // The centre of the lower screen (kLower): with -480 the game's items sat 12 px above the y they were given, and
        // the UI's own items (Developer, Team Creator) did not (owner, 2026-11-07). The given y already allows for it.
        dy=-kLower+(120-cy)/.475f-c->pos.y*zoom;
    } else if(carousel<0) hidden=true;
    // A modal owns both screens. Parent controls must not show through its window
    // or remain touchable while a save/progress/confirmation dialog is active.
    if(w3d_fe_popup_depth()>0 && *(int *)ptr < w3d_fe_popup_depth()) hidden=true;
    if(match) dy+=480; // The HUD camera pass is routed to the lower target after culling.
    // A placed group pops in as one piece (no stagger inside it), around its anchor.
    const Place *placed=find_place(m,n);
    if(placed) e.order=0;
    // Pages of the UI over a menu whose controls step aside (owner, 2026-11-07): Create Team under its Outfit page (the
    // page draws the rest below) and Multiplayer under the team window (the team's worm and roster go above, where the
    // game settings were). The titles stay. The controls shrink away as when their menu is left (0.14 s) and pop in
    // again when the page closes.
    float aside=1;
    {
        static int outfit_was, team_was; static double outfit_at, team_at;
        const int outfit=w3d_ui_outfit_open(), team=team_window();
        const double t=seconds();
        if(outfit!=outfit_was) {
            outfit_at=t; outfit_was=outfit;
            if(!outfit) for(unsigned k=0;k<entry_count;++k) if(!strcmp(entries[k].menu,"FE.Create Edit Team")) entries[k].born=t-.1;
        }
        if(team!=team_was) {
            team_at=t; team_was=team;
            if(!team) for(unsigned k=0;k<entry_count;++k) if(!strcmp(entries[k].menu,"FE.MultiplayerMenu")) entries[k].born=t-.1;
        }
        auto away=[&](double at) { const float k=(float)(t-at)/.14f; return k>=1?0.f:1-k*k; };
        if(outfit && !strcmp(m,"FE.Create Edit Team") && strcmp(n,"Title")) aside=away(outfit_at);
        if(team && !strcmp(m,"FE.MultiplayerMenu") && strcmp(n,"Title")) aside=away(team_at);
    }
    const float pop=hidden || w3d_fe_game_mode()!=6 ? 1 : transition(e)*aside;
    if(pop<=0) hidden=true;
    // Suppress the complete control subtree; no opaque panels cover old geometry.
    call_virtual<void>(p->base.get(),88,hidden?0:7);
    e.touch=e.bottom=false;
    if(hidden) { move(p->base.get(),{0,-10000,0}); scale(p->base.get(),{0,0,0}); return; }
    e.visible=true;
    Config *c=p->cfg.get();
    // The frame takes the new centre and the base, hanging from the animated locator,
    // only the zoom: the locator's original motion stays local and is not amplified.
    // A separate depth plane identifies FE controls in the native HUD camera.
    // Metal uses it to keep inventory/dialogs separate from the four indicators.
    {
        float fx=zoom*c->pos.x+dx, fy=zoom*c->pos.y+dy;
        if(placed && pop!=1) {
            const float axs=placed->tx, ays=placed->ty-(placed->screen?kLower:0);
            fx=axs+pop*(fx-axs); fy=ays+pop*(fy-ays);
        }
        // Pruebas (v43): W3D_COMBO_Z=<dz> adelanta (o atrasa) en z el desplegable abierto.
        float fz=c->pos.z;
        { static float dz=-1e9f; if(dz<-1e8f) { const char *e=getenv("W3D_COMBO_Z"); dz=e?(float)atof(e):0; }
          if(dz!=0 && *(const w3d_u32 *)((const char *)ptr-28)==w3d::h2g(A8041c790) && *(const int *)((const char *)ptr+160)==1) fz+=dz; }
        if(p->frame) move(p->frame.get(),{fx,fy,fz});
    }
    move(p->base.get(),{0,0,match?2.f:0.f});
    const float wx=placed && placed->wx>0 ? placed->wx : 1;
    scale(p->base.get(),{zoom*pop*wx,zoom*pop,zoom*pop});
    e.depth=*(int *)ptr;
    e.zoom=zoom;e.dx=dx;e.dy=dy;
    const bool navigable=e.linked;
    e.bottom=screen>=0 ? screen==1 : (c->pos.y*zoom+dy-(match?480:0))<-240;
    e.touch=e.bottom && navigable && *(int *)((char *)ptr+112);
    e.x=160+(c->pos.x*zoom+dx)*0.475f; e.y=120-(c->pos.y*zoom+dy+(match?0:kLower))*0.475f;
    e.w=fabsf(c->size.x)*zoom*0.95f; e.h=fabsf(c->size.y)*zoom*0.95f;
    // Tests: W3D_DUMP_PANEL=<control> logs that control's small-integer words when they change (list state).
    static const char *dump=getenv("W3D_DUMP_PANEL");
    if(dump && !strcmp(n,dump)) {
        static unsigned prev[192]; static bool have;
        const unsigned *w=(const unsigned *)ptr;
        struct timespec ts; clock_gettime(CLOCK_MONOTONIC,&ts); static double t0=ts.tv_sec+ts.tv_nsec*1e-9;
        const double t=ts.tv_sec+ts.tv_nsec*1e-9-t0;
        for(int k=0;k<192;++k) {
            const unsigned v=w[k]; float f,g; memcpy(&f,&v,4); memcpy(&g,&prev[k],4);
            const bool small=v<256 && prev[k]<256, whole=f>=0 && f<=64 && g>=0 && g<=64 && (f==floorf(f) || g==floorf(g));
            if(have && v!=prev[k] && small) w3d_dbg("[panel] %.2f %s +%d: %u -> %u\n",t,n,k*4,prev[k],v);
            else if(have && v!=prev[k] && whole) w3d_dbg("[panel] %.2f %s +%d: %.3f -> %.3f f\n",t,n,k*4,(double)g,(double)f);
            prev[k]=v;
        }
        // v42: la primera vez, todas las palabras (para buscar campos que no cambian: el número de filas de un desplegable).
        if(!have) { w3d_dbg("[panel] %s todo:",n); for(int k=0;k<192;++k) w3d_dbg(" %d:%x",k*4,w[k]); w3d_dbg("\n"); }
        have=true;
    }
}
// core/sdk/sdk_audio.cpp (sndFXStartEx): with two screens the team popup (FE.PopTeamAdjust) is a page of the UI and the
// game's own controls stay hidden, but their opening animation still played its two "pop" sounds (fx 93) with nothing
// opening on screen (owner, 2026-11-07: "no sé por qué hace ese ruido"). Muted for 1.2 s after the popup is created.
extern "C" int w3d_fx_muted(unsigned fid) {
    if(fid!=93 || !dual()) return 0;
    const double now=seconds();
    for(unsigned i=0;i<entry_count;++i) if(!strcmp(entries[i].menu,"FE.PopTeamAdjust") && now-entries[i].born<1.2) return 1;
    return 0;
}
// Screen of a placed control (0 upper, 1 lower), -1 if the menu does not place it.
extern "C" int w3d_fe_place_screen(const char *menu,const char *name) {
    const Place *p=menu && name ? find_place(menu,name) : nullptr;
    return p ? p->screen : -1;
}
extern "C" const char *w3d_fe_native_hit(const char *menu,float x,float y) {
    if(!menu) return nullptr;
    static const bool tlog=getenv("W3D_TOUCH_LOG")!=nullptr;   // pruebas: qué controles hay bajo el toque
    if(tlog) for(unsigned i=0;i<entry_count;++i) { const Entry &e=entries[i];
        if(!strcmp(e.menu,menu) && x>=e.x-e.w/2 && x<e.x+e.w/2 && y>=e.y-e.h/2 && y<e.y+e.h/2)
            w3d_dbg("[toque] %.0f,%.0f %s touch %d bottom %d linked %d +112 %d depth %d/%d\n",x,y,e.name,e.touch,e.bottom,e.linked,*(int *)((char *)e.panel+112),e.depth,w3d_fe_popup_depth()); }
    for(unsigned i=entry_count;i>0;--i) {
        Entry &e=entries[i-1];
        if(e.touch && e.depth==w3d_fe_popup_depth() && !strcmp(e.menu,menu) && x>=e.x-e.w/2 && x<e.x+e.w/2 && y>=e.y-e.h/2 && y<e.y+e.h/2) return e.name;
    }
    return nullptr;
}
// State of a native ListControl (Barracks, Team Roster), read the way the pad changes it: +160 the list is
// entered, +272 the selected row, +284 the first visible row (target of the animated scroll at +280).
// Geometry: the control's lower-screen centre and its pixels per original unit. Only controls updated in
// the last 0.25 s count (destroyed menus leave stale entries).
extern "C" int w3d_fe_native_list(const char *menu,const char *name,int *entered,int *selected,float *top,float *x,float *y,float *k) {
    const double now=seconds();
    for(unsigned i=entry_count;i>0;--i) {
        const Entry &e=entries[i-1];
        if(!e.bottom || now-e.seen>.25 || strcmp(e.menu,menu) || strcmp(e.name,name)) continue;
        const char *p=(const char *)e.panel;
        *entered=*(const int *)(p+160); *selected=*(const int *)(p+272); *top=*(const float *)(p+284);
        *x=e.x; *y=e.y; *k=.475f*e.zoom;
        return 1;
    }
    return 0;
}
// The same for an open drop-down (ComboControl): +160 open, +268 the selected row, +276 its first visible row as drawn
// (scrolling; +280 is where it goes). Nine rows show at a time. Measured with W3D_DUMP_PANEL (2026-11-07).
// v42 (el dueño, con la v41: «en las listas desplegables es horrible elegir con la pantalla táctil: las abres pero no
// puedes hacer scroll ni agarrar la barra; tiene que funcionar bien en todos los menús»). Cualquier desplegable del juego
// abierto en la pantalla de abajo del menú en curso: todos son de la misma clase (ComboControl, su tabla virtual en
// 0x8041c790; el control cuelga 28 bytes antes de su panel, como la tragaperras). Campos como w3d_fe_native_combo.
// count: sus filas, de la tabla del FE a la que está atado (GameDataId: FE.SoundBanks, FE.FlagsList...), buscando entre
// las primeras palabras del control un puntero a un texto «FE.» que sea una tabla; -1 si no se encuentra.
extern "C" char A8041c790[];
#if defined(__3DS__)
extern "C" { extern float w3d_combo_rect[4]; extern volatile double w3d_combo_rect_at; }   // gx_pica.cpp (combo_defer)
#endif
struct W3dCombo { const char *name; float x, y, k, half; int selected; float top; int count; };
#if defined(__3DS__)
// libctru: el montón de newlib (la memoria del juego), la memoria lineal y la imagen del programa (datos del juego).
extern "C" char *fake_heap_start, *fake_heap_end, __end__[];
extern "C" uint32_t __ctru_linear_heap, __ctru_linear_heap_size;
#endif
static bool readable(w3d_u32 a) {
#if defined(__3DS__)
    if (a >= (w3d_u32)(uintptr_t)fake_heap_start && a + 64 < (w3d_u32)(uintptr_t)fake_heap_end) return true;
    if (a >= __ctru_linear_heap && a + 64 < __ctru_linear_heap + __ctru_linear_heap_size) return true;
    return a >= 0x00100000u && a + 64 < (w3d_u32)(uintptr_t)__end__;
#else
    (void)a; return false;
#endif
}
extern "C" int w3d_fe_table(const char *name, char (*out)[64], int max);
// Un texto «FE.algo» que sea una tabla del FE: sus filas; 0 si no.
static int table_rows(w3d_u32 v) {
    if(!readable(v)) return 0;
    const char *t=(const char *)g2h(v);
    if(t[0]!='F' || t[1]!='E' || t[2]!='.') return 0;
    int n=0; while(n<48 && t[n]>32 && t[n]<127) ++n;
    if(n<4 || n>=48 || t[n]) return 0;
    // Recursos del FE que no son tablas (consejos, colores, imágenes de botones, textos de pantalla): ni se preguntan.
    if(!strncmp(t,"FE.Tip.",7) || !strncmp(t,"FE.Combo.",9) || !strncmp(t,"FE.B.",5) || !strncmp(t,"FE.Screen.",10) || !strncmp(t,"FE.Colour",9)) return 0;
    const int c=w3d_fe_table(t,nullptr,0);
    if(c>0 && getenv("W3D_COMBO_DUMP")) w3d_dbg("[combo] tabla %s: %d filas\n",t,c);
    return c>0?c:0;
}
// En el control, o un nivel más abajo (su descripción, donde va GameDataId): las primeras palabras de cada puntero.
static int combo_count(const char *control) {
    for(int off=0;off<1024;off+=4) if(const int c=table_rows(*(const w3d_u32 *)(control+off))) return c;
    for(int off=0;off<1024;off+=4) {
        const w3d_u32 v=*(const w3d_u32 *)(control+off);
        if(!readable(v) || !readable(v+256)) continue;
        const char *q=(const char *)g2h(v);
        for(int k=0;k<256;k+=4) if(const int c=table_rows(*(const w3d_u32 *)(q+k))) return c;
    }
    return -1;
}
extern "C" int w3d_fe_open_combo(const char *menu, W3dCombo *o) {
    const double now=seconds();
    const w3d_u32 vt=w3d::h2g(A8041c790);
    for(unsigned i=entry_count;i>0;--i) {
        const Entry &e=entries[i-1];
        if(!e.bottom || now-e.seen>.25 || strcmp(e.menu,menu)) continue;
        const char *p=(const char *)e.panel;
        if(*(const w3d_u32 *)(p-28)!=vt || *(const int *)(p+160)!=1) continue;
        static const void *counted; static int count;
        if(counted!=p) {
            counted=p; count=combo_count(p-28); w3d_dbg("[combo] %s / %s abierto: %d filas\n",menu,e.name,count);
            // Pruebas: W3D_COMBO_DUMP=1 escribe las palabras del control abierto y los textos a los que apuntan.
            static const bool dump=getenv("W3D_COMBO_DUMP")!=nullptr;
            if(dump) for(int off=0;off<1024;off+=4) {
                const w3d_u32 v=*(const w3d_u32 *)(p-28+off);
                char txt[24]=""; if(readable(v)) { const char *t=(const char *)g2h(v); int n=0; while(n<20 && t[n]>=32 && t[n]<127) { txt[n]=t[n]; ++n; } txt[n]=0; if(n<3) txt[0]=0; }
                if(v) w3d_dbg("[combo] +%d %08x %s%s\n",off,(unsigned)v,readable(v)?"*":"",txt);
            }
        }
        o->name=e.name; o->x=e.x; o->y=e.y; o->k=.475f*e.zoom; o->half=e.w*.45f;
        // v43: su rectángulo para el dibujo (gx_pica.cpp, combo_defer): el control y su lista con la barra, en píxeles de abajo.
#if defined(__3DS__)
        w3d_combo_rect[0]=e.x-e.w*.5f-4; w3d_combo_rect[1]=e.x+e.w*.5f+8;
        w3d_combo_rect[2]=e.y-e.h*.5f-2; w3d_combo_rect[3]=e.y+25.6f*o->k+10*32.2f*o->k+20; w3d_combo_rect_at=now;
#endif
        o->selected=*(const int *)(p+268); o->top=*(const float *)(p+276); o->count=count;
        return 1;
    }
    return 0;
}
// v42: mueve un desplegable abierto como lo haría su propio código: top < 0 deja la vista, selected < 0 deja la fila
// elegida. +276 es la primera fila que se dibuja y +280 adónde va (la vista se queda quieta si son iguales).
extern "C" int w3d_fe_combo_set(const char *menu, const char *name, int selected, float top) {
    const double now=seconds();
    const w3d_u32 vt=w3d::h2g(A8041c790);
    for(unsigned i=entry_count;i>0;--i) {
        Entry &e=entries[i-1];
        if(!e.bottom || now-e.seen>.25 || strcmp(e.menu,menu) || strcmp(e.name,name)) continue;
        char *p=(char *)e.panel;
        if(*(const w3d_u32 *)(p-28)!=vt || *(const int *)(p+160)!=1) return 0;
        if(top>=0) { *(float *)(p+276)=top; *(float *)(p+280)=top; }
        if(selected>=0) *(int *)(p+268)=selected;
        return 1;
    }
    return 0;
}
extern "C" int w3d_fe_native_combo(const char *menu,const char *name,int *open,int *selected,float *top,float *x,float *y,float *k) {
    const double now=seconds();
    for(unsigned i=entry_count;i>0;--i) {
        const Entry &e=entries[i-1];
        if(!e.bottom || now-e.seen>.25 || strcmp(e.menu,menu) || strcmp(e.name,name)) continue;
        const char *p=(const char *)e.panel;
        *open=*(const int *)(p+160); *selected=*(const int *)(p+268); *top=*(const float *)(p+276);
        *x=e.x; *y=e.y; *k=.475f*e.zoom;
        return 1;
    }
    return 0;
}
extern "C" int w3d_fe_weapon_cell(int index,int *locked) {
    if(index<0 || index>=54) return -1;
    *locked=weapon_cells[index].locked;
    return weapon_cells[index].icon;
}

extern "C" int A802aa8a4(void *,int);
extern "C" void A802aaa8c(void *);
static int pending_wormpot=-1;
extern "C" void w3d_fe_wormpot_action(int action) {
    // The touch UI runs inside scene rendering. Starting an animation here
    // destroys nodes that the current traversal still holds (PC 0 in 801a38c8).
    if(action==2 || action==3 || action==5 || action==6 || action==8 || action==9 || action==10)
        pending_wormpot=action;
}
extern "C" void w3d_fe_wormpot_flush(void) {
    const int action=pending_wormpot; pending_wormpot=-1;
    const char *menu=w3d_test_fe_menu();
    if(action<0 || w3d_fe_game_mode()!=6 || w3d_fe_popup_depth()!=0 || !menu || strcmp(menu,"FE.Wormpot")) return;
    for(unsigned i=entry_count;i>0;--i) {
        Entry &e=entries[i-1];
        if(strcmp(e.menu,"FE.Wormpot") || strcmp(e.name,"New.WormPot") || !e.visible || seconds()-e.seen>.25) continue;
        void *owner=(char *)e.panel-28; // FruitMachine::sub, original 802a8650.
        if(*((unsigned *)((char *)owner+1340))) return; // Native spin/nudge still active.
        A802aa8a4(owner,action);
        A802aaa8c(owner);
        return;
    }
}

// Small, bounded UI evidence for SELECT reports. Read saved metadata only;
// never dereference registry pointers after menu teardown.
extern "C" void w3d_fe_dump_ui(const char *dir) {
    char path[192]; snprintf(path,sizeof path,"%s/ui.txt",dir);
    FILE *f=fopen(path,"wb"); if(!f) return;
    if(w3d_fe_game_mode()!=6 && w3d_fe_game_mode()!=7) {
        fprintf(f,"Escena original, modo=%d; sin controles de menu superpuestos.\n",w3d_fe_game_mode());
        fclose(f);return;
    }
    double t=0; for(unsigned i=0;i<entry_count;++i) if(entries[i].seen>t)t=entries[i].seen;
    fprintf(f,"menu/control | pantalla | centro x,y | ancho,alto | tactil | profundidad\n");
    for(unsigned i=0;i<entry_count;++i) {
        const Entry &e=entries[i];
        if(t-e.seen>0.2) continue;
        fprintf(f,"%s/%s | %s | %.2f,%.2f | %.2f,%.2f | %d | %d\n",e.menu,e.name,
            !e.visible?"oculto":e.bottom?"inferior":"superior",e.visible && !e.bottom?e.x+40:e.x,e.visible && !e.bottom && w3d_fe_game_mode()==6?e.y+240:e.y,e.w,e.h,e.touch,e.depth);
    }
    fclose(f);
}
