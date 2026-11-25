// Beta 0.1: original weapon models above the native weapon-options controls.
// Assets: tools/build3ds/ui/export_weapons.py. Only the current mesh/atlas stays
// resident; vertex floats are copied into aligned storage (required on ARM11).
#include "ui.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

namespace ui {
namespace {
const char *const kTips[]={"Bazooka","Mortar","HomingM","Astrike","Grenade","Cluster","Gas","Banana",
    "Shotgun","Uzi","OWoman","MadCow","Jetpack","Rope","Para","BridgeK",
    "Fball","Pigeon","Axe","Bat","Prod","HolyHG","Teleport","Mine","SSheep","Petrol","Sheep","TNT",
    "Nuke","Girder","Wselect","EQuake"};
const char *const kControls[]={"Bazooka","Mortar","HomingM","Air Strike","Grenade","Cluster","Gas","Banana",
    "Shotgun","Uzi","Old Woman","Mad Cows","Jet Pack","Rope","Para","Bridge Kit"};
int current=-1;
unsigned width, height;
std::vector<float> mesh, projected, output;
std::vector<unsigned char> pixels;
std::vector<unsigned> colors, output_colors;
struct Triangle {float depth;unsigned first;};
std::vector<Triangle> order;
double started;
unsigned read32(const unsigned char *p) {return p[0]|unsigned(p[1])<<8|unsigned(p[2])<<16|unsigned(p[3])<<24;}
bool worm(int n) {return n==16 || n==30;}
void load(int n) {
    img_mem_forget("weapon_preview");
    mesh.clear(); pixels.clear(); current=n; started=now();
    if(n<0) return;
    if(worm(n)) {gusano_turn_reset();return;}
    char file[64];snprintf(file,sizeof file,"weapons/%s.w3wp",kTips[n]);
    unsigned char *data=nullptr;long len=0;
    if(!uib_read_own(file,&data,&len) || !data) {uib_log("[weapon3d] missing %s\n",file);return;}
    bool valid=len>=20 && !memcmp(data,"W3WP",4) && read32(data+4)==1;
    unsigned nv=valid?read32(data+8):0; width=valid?read32(data+12):0;height=valid?read32(data+16):0;
    valid=valid && nv>=3 && nv<=18000 && nv%3==0 && width>=8 && width<=1024 && height>=8 && height<=1024
          && !(width&(width-1)) && !(height&(height-1)) && size_t(len)==20+size_t(nv)*32+size_t(width)*height*4;
    if(valid) {
        mesh.resize(size_t(nv)*8);memcpy(mesh.data(),data+20,mesh.size()*4);
        for(float v:mesh) if(!std::isfinite(v)) {valid=false;break;}
        if(valid) pixels.assign(data+20+nv*32,data+len);
    }
    uib_free(data);
    if(!valid) {mesh.clear();uib_log("[weapon3d] invalid %s\n",file);return;}
    uib_log("[weapon3d] %s: %u vertices, %ux%u\n",kTips[n],nv,width,height);
}
float dot(const float *p,const float *q) {return p[0]*q[0]+p[1]*q[1]+p[2]*q[2];}
}

void weapon_preview_clear() {
    if(current<0) return;
    load(-1);
    std::vector<float>().swap(mesh);std::vector<unsigned char>().swap(pixels);
    std::vector<float>().swap(projected);std::vector<float>().swap(output);
    std::vector<unsigned>().swap(colors);std::vector<unsigned>().swap(output_colors);
    std::vector<Triangle>().swap(order);
}

void weapon_preview() {
    int selected=-1;
    const char *control=w3d_fe_highlighted();
    // FE.ToolTip already contains localized text. Use the native control and
    // page instead, so changing language cannot select the wrong model.
    const int page=w3d_fe_prop_int("FE.Page",int(w3d_fe_prop_uint("FE.Page",0)));
    if(control && (page==0 || page==1))
        for(int i=0;i<16;++i) if(!strcmp(control,kControls[i])) {selected=i+16*page;break;}
    if(selected<0) {weapon_preview_clear();return;}
    if(selected!=current) load(selected);
    if(worm(selected)) {
        gusano_turn(1);gusano_draw(0,200,125,160,0,1);return;
    }
    if(mesh.empty()) return;
    const Img *atlas=img_mem("weapon_preview",pixels.data(),width,height,1);
    if(atlas->tex<0) return;
    const float yaw=-0.5f+float(fmod(now()-started,12.0))*6.2831853f/12.0f, pitch=0.20f;
    const float right[3]={cosf(yaw),0,-sinf(yaw)};
    const float back[3]={sinf(yaw)*cosf(pitch),sinf(pitch),cosf(yaw)*cosf(pitch)};
    const float up[3]={-sinf(yaw)*sinf(pitch),cosf(pitch),-cosf(yaw)*sinf(pitch)};
    float light[3];for(int k=0;k<3;++k)light[k]=-.35f*right[k]+.6f*up[k]+.7f*back[k];
    const unsigned nv=mesh.size()/8;projected.resize(nv*5);colors.resize(nv);order.clear();
    // A unit sphere at 70px radius leaves room for the title and full help line.
    for(unsigned i=0;i<nv;++i) {
        const float *v=&mesh[i*8];float *p=&projected[i*5];
        p[0]=200+70*dot(v,right);p[1]=121-70*dot(v,up);p[2]=.5f-.20f*dot(v,back);
        p[3]=v[6]*float(width)/atlas->pw;p[4]=v[7]*float(height)/atlas->ph;
        unsigned c=unsigned(255*fminf(1,.55f+.45f*fmaxf(0,dot(v+3,light))));
        colors[i]=c|c<<8|c<<16|unsigned(faded(0xffffffff)&255)<<24;
    }
    for(unsigned i=0;i<nv;i+=3) order.push_back({projected[i*5+2]+projected[(i+1)*5+2]+projected[(i+2)*5+2],i});
    std::sort(order.begin(),order.end(),[](const Triangle&a,const Triangle&b){return a.depth>b.depth;});
    output.resize(nv*5);output_colors.resize(nv);unsigned dst=0;
    for(const auto &t:order) for(unsigned k=0;k<3;++k,++dst) {
        memcpy(&output[dst*5],&projected[(t.first+k)*5],5*sizeof(float));output_colors[dst]=colors[t.first+k];
    }
    tris_under(0,atlas->tex,output.data(),output_colors.data(),nv);
}
} // namespace ui
