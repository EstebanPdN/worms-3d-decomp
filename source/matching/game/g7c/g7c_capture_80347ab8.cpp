// External object views; never constructed locally.
struct RefView;
struct RefTable {void *slots[3];int (*retain)(RefView *);int (*release)(RefView *);};
struct RefView {RefTable *table;};
struct SurfaceView {RefTable *table;char unknown04[40];unsigned short height,width;};
struct RendererView;
struct RendererTable {void *slots[7];int (*dimensions)(RendererView *,unsigned int *,unsigned int *);void *slot8;void (*capture)(RendererView *,int,int,unsigned int,unsigned int,SurfaceView *,int,int);};
struct RendererView {RendererTable *table;};
struct ControllerView {char unknown00[92];RendererView *renderer;};
struct FilesView;
struct FilesTable {void *slots[5];int (*open)(FilesView *,const char *,int,RefView **);int (*exists)(FilesView *,const char *,int,RefView **);};
struct FilesView {FilesTable *table;};
extern "C" {
extern char g7c_descriptor_80415cc0[];
extern const char g7c_pattern_803a4514[];
extern unsigned int g7c_counter_804ab464;
SurfaceView *g7c_surface_8020b680(void *);
FilesView *g7c_files_8020b884();
void g7c_prepare_801afac0(SurfaceView *);
int g7c_encode_801a4d68(SurfaceView *,RefView *,int,int);
int g7c_format_80347a10(char *,const char *,...);
}
template<class T> struct Held {
 T *pointer;
 Held(T *p):pointer(p) {if(p)((RefView *)p)->table->retain((RefView *)p);}
 Held():pointer(0) {}
 ~Held(){if(pointer)((RefView *)pointer)->table->release((RefView *)pointer);}
 void reset(T *replacement=0){if(pointer)((RefView *)pointer)->table->release((RefView *)pointer);pointer=replacement;}
};
struct Buffer {char data[64];Buffer(){data[0]=0;}};
extern "C" int w3d_g7c_capture_80347ab8(ControllerView *self,const char *path,FilesView *files) {
 Held<SurfaceView> surface(g7c_surface_8020b680(g7c_descriptor_80415cc0));
 unsigned int width,height;
 self->renderer->table->dimensions(self->renderer,&width,&height);
 surface.pointer->width=(unsigned short)width;
 surface.pointer->height=(unsigned short)height;
 g7c_prepare_801afac0(surface.pointer);
 self->renderer->table->capture(self->renderer,0,0,width,height,surface.pointer,0,0);
 Held<RefView> file;
 Buffer buffer;
 if(!files)files=g7c_files_8020b884();
 if(!path){
  for(;;){
   file.reset();
   g7c_format_80347a10(buffer.data,g7c_pattern_803a4514,g7c_counter_804ab464);
   if(files->table->exists(files,buffer.data,1,&file.pointer)<0)break;
   ++g7c_counter_804ab464;
  }
  path=buffer.data;
 }
 int result=files->table->open(files,path,6,&file.pointer);
 if(result<0)return result;
 g7c_encode_801a4d68(surface.pointer,file.pointer,0,0);
 return 0;
}
