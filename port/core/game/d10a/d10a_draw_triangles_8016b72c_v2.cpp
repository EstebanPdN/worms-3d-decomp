#include "w3d_ptr.h"
#line 1 "d10a_draw_triangles_8016b72c_v2.cpp"
// Partial views for cached triangle display lists. Unknown fields remain opaque;
// sixteen-byte list allocation and callback argument order are witnessed.
struct d10a_DrawInterface;
struct d10a_DrawOwner;
struct d10a_Mesh;
struct d10a_List { unsigned vertices,size,attributes; Ptr32<void> data; };
struct d10a_MeshData { unsigned char unknown[20]; Ptr32<d10a_List> list; };
struct d10a_Cache;
struct d10a_CacheTable { unsigned unknown[9]; Ptr32<void (Ptr32<d10a_Cache>, Ptr32<d10a_MeshData>, Ptr32<d10a_List>, unsigned int)> publish; };
struct d10a_Cache { Ptr32<d10a_CacheTable> table; };
struct d10a_DrawOwner {
 unsigned char unknown[148]; Ptr32<d10a_Cache> cache;
 unsigned char unknown152[8]; Ptr32<void> cursor;
 unsigned char unknown164[124]; unsigned format,attributes;
};
struct d10a_Mesh { unsigned char unknown[84]; unsigned triangles; unsigned unknown88; Ptr32<d10a_MeshData> data; };
struct d10a_Renderer;
extern Ptr32<d10a_Renderer> d10a_renderer_804b1884;
extern "C" int d10a_apply_mesh_8016b5a0(Ptr32<d10a_DrawInterface>,Ptr32<d10a_Mesh>);
// These helpers have side-effect-only returns; direct definitions were inspected.
extern "C" void d10a_set_format_8016797c(Ptr32<d10a_Renderer>,unsigned,unsigned,Ptr32<d10a_DrawInterface>);
extern "C" Ptr32<void> d10a_allocate_80166fd0(Ptr32<d10a_Renderer>,unsigned);
extern "C" void d10a_begin_list_8016aef0(Ptr32<d10a_List>,unsigned,unsigned,Ptr32<d10a_DrawOwner>);
extern "C" void d10a_emit_8016b384(unsigned,unsigned,unsigned,Ptr32<d10a_DrawOwner>);
extern "C" void d10a_save_list_8016afc8(Ptr32<d10a_List>);
extern "C" void d10a_finish_streams_8016b040(unsigned,Ptr32<d10a_Mesh>,Ptr32<d10a_DrawOwner>);
extern "C" void d10a_call_list_8016aec0(Ptr32<d10a_List>);
extern "C" int d10a_draw_triangles_8016b72c(Ptr32<d10a_DrawInterface> input,Ptr32<d10a_Mesh> mesh)
{
 Ptr32<d10a_DrawOwner> self=input?w3d::R((Ptr32<d10a_DrawOwner>)((Ptr32<char>)input-4)):0;
 unsigned count=mesh->triangles*3u;
 if(count==0) return 0;
 int result=d10a_apply_mesh_8016b5a0(input,mesh);
 unsigned format=self->format;
 d10a_set_format_8016797c(d10a_renderer_804b1884,format,5,self?w3d::R((Ptr32<d10a_DrawInterface>)((Ptr32<char>)self+4)):0);
 if(result!=0) return result;
 Ptr32<d10a_MeshData> data=mesh->data;
 Ptr32<d10a_List> list;
 Ptr32<d10a_List> cached=data->list;
 if(!cached) {
   Ptr32<void> saved=self->cursor;
   unsigned short vertices=count;
   list=(Ptr32<d10a_List>)d10a_allocate_80166fd0(d10a_renderer_804b1884,16);
   d10a_begin_list_8016aef0(list,format,vertices,self);
   d10a_emit_8016b384(144,format,vertices,self);
   d10a_save_list_8016afc8(list);
   self->cursor=saved;
   list->attributes=self->attributes;
   data->list=list;
   self->cache->table->publish(self->cache,data,list,0);
   d10a_finish_streams_8016b040(format,mesh,self);
 } else {
   list=cached;
 }
 if(list) d10a_call_list_8016aec0(list);
 return 0;
}


