// Observed seven-tap byte filter and float factor. Partial object views only.
struct cc45a_FilterMode { unsigned char unknown00[50]; unsigned char filter[7]; };
struct cc45a_FilterDisplay { unsigned char unknown00[40]; cc45a_FilterMode *mode; unsigned char unknown2c[500]; float factor; unsigned char filter[7]; };
inline float cc45a_lower(float x,float bound) { if(x<bound) return bound; return x; }
inline float cc45a_upper(float x,float bound) { if(x>bound) return bound; return x; }
extern "C" void cc45a_filter_scale_8016ee4c(cc45a_FilterDisplay *self,float factor) {
 self->factor=factor;
 factor=cc45a_upper(cc45a_lower(factor,0.0f),2.0f);
 for(unsigned int i=0;i<7;++i) self->filter[i]=(unsigned char)((float)self->mode->filter[i]*factor);
}
