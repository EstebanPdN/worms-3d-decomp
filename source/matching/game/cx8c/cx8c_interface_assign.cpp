/* Layout offsets and call addresses observed in the original. Names and object roles are inferred. */
struct Cx8cInterface {void **vtable;};
struct Cx8cOwner {unsigned char unknown[120];Cx8cInterface *held;};
extern "C" unsigned int w3d_cx8c_interface_assign_8034bb44(Cx8cOwner *self,Cx8cInterface *value) {
 if (value!=self->held) {if (self->held) ((void (*)(Cx8cInterface *))self->held->vtable[4])(self->held);self->held=value;if(value) ((void (*)(Cx8cInterface *))value->vtable[3])(value);}
 return self->held?0:0x80070057;
}
