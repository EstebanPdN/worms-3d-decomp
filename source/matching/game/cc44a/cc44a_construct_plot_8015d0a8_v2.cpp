// Partial layout inferred from original stores; names are descriptive hypotheses.
struct cc44a_PlotData;
struct cc44a_PlotVtable {
 unsigned int unknown[3];
 void (*retain)(cc44a_PlotData *);
 void (*release)(cc44a_PlotData *);
 unsigned int unknown20[3];
 void (*resize)(cc44a_PlotData *, int);
};
struct cc44a_PlotData { cc44a_PlotVtable *vtable; };
struct cc44a_PlotPair { unsigned int unknown0, second; cc44a_PlotPair() { second=0; } };
struct cc44a_PlotColor {
 float x,y,z,w;
 cc44a_PlotColor &operator=(const cc44a_PlotColor &c) { float a=c.x,b=c.y,e=c.z,d=c.w; x=a; y=b; z=e; w=d; return *this; }
 cc44a_PlotColor() {}
 cc44a_PlotColor(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}
};
struct cc44a_Plot {
 void *first;
 unsigned int second;
 cc44a_PlotPair pair;
 unsigned int word16,word20;
 cc44a_PlotData *data;
 float value28,value32;
 cc44a_PlotColor color;
 unsigned short count;
 cc44a_Plot();
};
// Factory 80208aac returns its allocated object; its argument is stored as a full word.
extern "C" cc44a_PlotData *cc44a_create_plot_data_80208aac(unsigned int);
cc44a_Plot::cc44a_Plot():first(0),second(0),word16(0),word20(0),data(0) {
 color=cc44a_PlotColor(1.0f,0.0f,0.5f,0.5f);
 cc44a_PlotData *fresh=cc44a_create_plot_data_80208aac(0);
 if(fresh) fresh->vtable->retain(fresh);
 if(data) data->vtable->release(data);
 data=fresh;
 fresh->vtable->resize(fresh,2048);
 data->vtable->resize(data,0);
 value32=value28=0.0f;
 count=12;
}
