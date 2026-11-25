// Partial intrusive callback-list and two-word descriptor views.
struct cc45a_Callback;
struct cc45a_CallbackOwner { unsigned char unknown00[24]; cc45a_Callback *head; };
struct cc45a_CallbackDescriptor { unsigned int flags, value; };
extern "C" {
extern const cc45a_CallbackDescriptor cc45a_default_803a45c4[];
void cc45a_link_8015f7e0(cc45a_Callback*,cc45a_Callback**,void*,cc45a_CallbackOwner*,void*,cc45a_CallbackDescriptor);
int cc45a_callback_default_8015fb6c(cc45a_CallbackOwner *self,void *callback,cc45a_Callback *node,void *context,cc45a_CallbackDescriptor descriptor) {

 if((short)descriptor.flags) cc45a_link_8015f7e0(node,&self->head,callback,self,context,descriptor);
 else {descriptor=cc45a_default_803a45c4[0];cc45a_link_8015f7e0(node,&self->head,callback,self,context,descriptor);}
 return 0;
}
}
