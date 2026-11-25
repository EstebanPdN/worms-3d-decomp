/* Observed eyebrow placement resource and transform application. */
extern "C" {
struct W3dS1EyebrowVec {float x,y,z;};
struct W3dS1EyebrowRef;
struct W3dS1EyebrowTable {void (*unused[19])();void (*position)(W3dS1EyebrowRef *,W3dS1EyebrowVec *,int);void (*rotate)(W3dS1EyebrowRef *,W3dS1EyebrowVec *,int);void (*scale)(W3dS1EyebrowRef *,W3dS1EyebrowVec *,int);};
struct W3dS1EyebrowRef {W3dS1EyebrowTable *vtable;};
struct W3dS1Eyebrow {char unknown[28];unsigned int handle;W3dS1EyebrowRef *resource;W3dS1EyebrowVec rotation;};
struct W3dS1EyebrowString {const char *text;int unknown;};
extern const char w3d_str_8037a070[];
extern W3dS1EyebrowVec w3d_vector_8045e788[];
void *w3d_fn_80164fc8(unsigned int);
W3dS1EyebrowVec *w3d_placement_offset_800672b0(void *);
W3dS1EyebrowVec *w3d_placement_target_800672a8(void *);
W3dS1EyebrowVec *w3d_placement_extra_800672b8(void *);
void w3d_string_from_text(void *,const char *);
void w3d_handle_set_name(void *,void *,unsigned int);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
#if 0 /* Excluded: four argument setup instructions remain exchanged after two attempts. */
int w3d_fn_80066bc4(W3dS1Eyebrow *self)
{
    void *placement=w3d_fn_80164fc8(self->handle);
    if(placement) {
        self->rotation.x+=w3d_placement_offset_800672b0(placement)->x;
        self->rotation.z+=w3d_placement_offset_800672b0(placement)->z;
        W3dS1EyebrowRef *resource=self->resource;
        resource->vtable->position(resource,w3d_placement_target_800672a8(placement),0);
        W3dS1EyebrowRef *second=self->resource;
        second->vtable->scale(second,w3d_placement_extra_800672b8(placement),0);
        self->resource->vtable->rotate(self->resource,&self->rotation,0);
    }
    return 0;
}
#endif
#if 0 /* Excluded: temporary string address caching differs after two attempts. */
void w3d_fn_80066c9c(W3dS1Eyebrow *self)
{
    W3dS1EyebrowString local;
    w3d_string_from_text(&local,w3d_str_8037a070);
    w3d_handle_set_name(&local,&self->resource,255);
    w3d_string_base_finish(&local);w3d_string_release(&local);
    self->rotation=w3d_vector_8045e788[0];
}
#endif
}
