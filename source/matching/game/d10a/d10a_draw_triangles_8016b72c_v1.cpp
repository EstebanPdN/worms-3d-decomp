// Partial views for cached triangle display lists. Unknown fields remain opaque;
// sixteen-byte list allocation and callback argument order are witnessed.
struct d10a_DrawInterface;
struct d10a_DrawOwner;
struct d10a_Mesh;
struct d10a_List { unsigned vertices,size,attributes; void *data; };
struct d10a_MeshData { unsigned char unknown[20]; d10a_List *list; };
struct d10a_Cache;
struct d10a_CacheTable { unsigned unknown[9]; void (*publish)(d10a_Cache *,d10a_MeshData *,d10a_List *,unsigned); };
struct d10a_Cache { d10a_CacheTable *table; };
struct d10a_DrawOwner {
 unsigned char unknown[148]; d10a_Cache *cache;
 unsigned char unknown152[8]; void *cursor;
 unsigned char unknown164[124]; unsigned format,attributes;
};
struct d10a_Mesh { unsigned char unknown[84]; unsigned triangles; unsigned unknown88; d10a_MeshData *data; };
struct d10a_Renderer;
extern d10a_Renderer *d10a_renderer_804b1884;
extern "C" int d10a_apply_mesh_8016b5a0(d10a_DrawInterface *,d10a_Mesh *);
// These helpers have side-effect-only returns; direct definitions were inspected.
extern "C" void d10a_set_format_8016797c(d10a_Renderer *,unsigned,unsigned,d10a_DrawInterface *);
extern "C" void *d10a_allocate_80166fd0(d10a_Renderer *,unsigned);
extern "C" void d10a_begin_list_8016aef0(d10a_List *,unsigned,unsigned,d10a_DrawOwner *);
extern "C" void d10a_emit_8016b384(unsigned,unsigned,unsigned,d10a_DrawOwner *);
extern "C" void d10a_save_list_8016afc8(d10a_List *);
extern "C" void d10a_finish_streams_8016b040(unsigned,d10a_Mesh *,d10a_DrawOwner *);
extern "C" void d10a_call_list_8016aec0(d10a_List *);
inline d10a_List *d10a_cached_triangles(d10a_DrawOwner *self,d10a_Mesh *mesh,unsigned format,unsigned count)
{
 d10a_MeshData *data=mesh->data;
 d10a_List *existing=data->list;
 if(!existing) {
   d10a_List *list;
   void *saved=self->cursor;
   unsigned short vertices=count;
   list=(d10a_List *)d10a_allocate_80166fd0(d10a_renderer_804b1884,16);
   d10a_begin_list_8016aef0(list,format,vertices,self);
   d10a_emit_8016b384(144,format,vertices,self);
   d10a_save_list_8016afc8(list);
   self->cursor=saved;
   list->attributes=self->attributes;
   data->list=list;
   self->cache->table->publish(self->cache,data,list,0);
   d10a_finish_streams_8016b040(format,mesh,self);
   return list;
 }
 return existing;
}
extern "C" int d10a_draw_triangles_8016b72c(d10a_DrawInterface *input,d10a_Mesh *mesh)
{
 d10a_DrawOwner *self=input?(d10a_DrawOwner *)((char *)input-4):0;
 unsigned count=mesh->triangles*3u;
 if(count==0) return 0;
 int result=d10a_apply_mesh_8016b5a0(input,mesh);
 unsigned format=self->format;
 d10a_set_format_8016797c(d10a_renderer_804b1884,format,5,self?(d10a_DrawInterface *)((char *)self+4):0);
 if(result!=0) return result;
 d10a_List *list=d10a_cached_triangles(self,mesh,format,count);
 if(list) d10a_call_list_8016aec0(list);
 return 0;
}
