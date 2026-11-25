
struct Cx8bDispatchObject;
typedef void (*Cx8bMethod)(Cx8bDispatchObject *);
struct Cx8bDispatchObject { char unknown00[24]; Cx8bMethod *methods; };
struct Cx8bMethodDescriptor { char unknown00[6]; unsigned short index; };
struct Cx8bBindingInput { char unknown00[52]; Cx8bMethodDescriptor *descriptor; };
extern "C" int w3d_cx8b_binding_slot_dispatch_801d9e18(char *secondary,Cx8bBindingInput *input) {
 char *base=secondary ? secondary-4 : 0;
 Cx8bDispatchObject *object=(Cx8bDispatchObject *)(base+4);
 Cx8bMethodDescriptor *descriptor=input->descriptor;
 ((void (*)(Cx8bDispatchObject *,Cx8bMethodDescriptor *))object->methods[descriptor->index])(object,descriptor);
 return 0;
}


