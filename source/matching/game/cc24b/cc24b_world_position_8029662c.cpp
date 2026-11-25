extern "C" float lbl_803d0834[];
struct Cc24bPositionVec {
 float x,y,z;
 Cc24bPositionVec(){} Cc24bPositionVec(float zero){x=zero;y=zero;z=zero;}
 Cc24bPositionVec(const Cc24bPositionVec &o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 inline Cc24bPositionVec &operator+=(const Cc24bPositionVec &o){x+=o.x;y+=o.y;z+=o.z;return *this;}
 Cc24bPositionVec(const Cc24bPositionVec &a,const Cc24bPositionVec &b){float u=a.x,v=a.y,w=a.z;x=u;y=v;z=w;*this+=b;}
 inline Cc24bPositionVec operator+(const Cc24bPositionVec &o)const{return Cc24bPositionVec(*this,o);}
 inline Cc24bPositionVec &operator=(const Cc24bPositionVec &o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;return *this;}
};
struct Cc24bPositionMatrix {float rotation[9];Cc24bPositionVec translation;inline Cc24bPositionVec &origin(){return translation;}};
struct Cc24bPositionBackend;
struct Cc24bPositionVtable {void *unknown[31];void (*read)(Cc24bPositionBackend*,Cc24bPositionMatrix*);};
struct Cc24bPositionBackend {Cc24bPositionVtable *vt;};
struct Cc24bPositionOwner {unsigned char unknown[32];Cc24bPositionVec offset;unsigned char gap[12];int active;unsigned char gap60[60];Cc24bPositionBackend *backend;};
extern "C" Cc24bPositionVec *w3d_cc24b_world_position_8029662c(Cc24bPositionVec *out,Cc24bPositionOwner *self){
 Cc24bPositionVec zero(lbl_803d0834[0]);
 if(!self->active)*out=zero;
 else {Cc24bPositionMatrix transform;self->backend->vt->read(self->backend,&transform);*out=transform.origin()+self->offset;}
 return out;
}
