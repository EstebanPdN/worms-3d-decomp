/* Observed gravestone creation message fields. */
extern "C" {
struct W3dS1GraveVector { float x,y,z; };
struct W3dS1GraveMessage { unsigned short id;unsigned short padding;void *vtable;W3dS1GraveVector position,direction;unsigned char style;unsigned char unknown[3];unsigned int owner; };
extern unsigned int w3d_message_804ad410;
extern unsigned char w3d_vtable_8040db38[];
unsigned int w3d_cached_message_id(void *,int);
W3dS1GraveMessage *w3d_fn_8004d870(W3dS1GraveMessage *self,const W3dS1GraveVector *position,const W3dS1GraveVector *direction,unsigned char style,unsigned int owner)
{
    self->id=w3d_cached_message_id(&w3d_message_804ad410,1);
    self->vtable=w3d_vtable_8040db38;
    self->position=*position;self->direction=*direction;
    self->style=style;self->owner=owner;
    return self;
}
}
