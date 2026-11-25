
struct Properties{unsigned char opaque[11];unsigned char flags;unsigned char rest[144];char*name;};struct Panel{unsigned char opaque[40];Properties*properties;unsigned char middle[96];int sound;unsigned char tail[32];int active; void run(int);};
extern "C" void update_802b0990(void*);extern "C" void sound_802b1258(const char*);extern "C" void start_802aa33c(Panel*);extern "C" void stop_802aa3a4(Panel*);
void Panel::run(int active){ Panel *self=this;if(self->active!=active){update_802b0990((unsigned char*)self+28);if(active){Properties*p=self->properties;char*t=p->name;if(*(unsigned short*)(t-4)&&((p->flags^4)&4)&&self->sound)sound_802b1258(t);start_802aa33c(self);}else stop_802aa3a4(self);}}

