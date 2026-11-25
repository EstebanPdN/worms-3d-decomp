// GWMP8P rev0, observed GC32 partial layouts. Built with -mps-float
// (paired-single FP frame: four saved FPRs, 8 bytes each below the save area).
// The unit owns its .rodata literal pool 0x803d80e0..0x803d80eb in first-use
// order (0.5f, 0.0f, 1.5f), decoded from the DOL.
// Owner, context and element names describe observed use only; they do not
// establish the original class identities.
typedef void (*D20fRefMethod)(void *);
struct D20fRefObject { D20fRefMethod *vtable; };
inline void d20f_retain(D20fRefObject *p) { if (p) p->vtable[3](p); }
inline void d20f_release(D20fRefObject *p) { if (p) p->vtable[4](p); }
// Retaining interface handle; passed by value (the callee releases it).
struct D20fHeld {
 D20fRefObject *p;
 D20fHeld(const D20fHeld &a) : p(a.p) { d20f_retain(p); }
 ~D20fHeld() { d20f_release(p); }
};
struct D20fVec3 {
 float x, y, z;
 D20fVec3() {}
 D20fVec3(const D20fVec3 &a) : x(a.x), y(a.y), z(a.z) {}
};
// 140-byte list element allocated through its class allocator 0x801fe1d8.
struct D20fListElement {
 unsigned words0[19];
 float size;
 unsigned words80[15];
 D20fListElement();
 static void *operator new(unsigned);
};
struct D20fListContext {
 unsigned words0[5];
 D20fVec3 dimensions;
 unsigned words32[24];
 float size;
 float margin;
 unsigned words136[2];
 unsigned value;
};
struct D20fListOwner {
 unsigned words0[7];
 unsigned text[1];
 unsigned layer;
 unsigned words36[1];
 D20fListContext *context;
 unsigned words44[17];
 D20fHeld interface112;
 unsigned words116[18];
 unsigned property;
 unsigned words192[7];
 float scale;
 unsigned words224[14];
 D20fHeld interface280;
 unsigned words284[3];
 unsigned selection;
 unsigned words300[26];
 D20fListElement *element;
};
typedef char D20fListOwnerSize[(sizeof(D20fListOwner) == 408) ? 1 : -1];
typedef char D20fListElementSize[(sizeof(D20fListElement) == 140) ? 1 : -1];
typedef char D20fListContextSize[(sizeof(D20fListContext) == 148) ? 1 : -1];
extern "C" float d20f_text_size_802b1880(void *text);
extern "C" void d20f_element_interface_802c0c24(D20fListElement *element, D20fHeld interface);
extern "C" void d20f_element_interface_802bdc88(D20fListElement *element, D20fHeld interface);
extern "C" void d20f_element_length_802bd3cc(D20fListElement *element, float length);
extern "C" void d20f_element_select_802bd2c4(D20fListElement *element, unsigned selection, int existing);
extern "C" void d20f_element_layer_802c0cac(D20fListElement *element, unsigned layer);
extern "C" void d20f_element_value_802bfb2c(D20fListElement *element, unsigned value);
extern "C" void d20f_element_height_802bfb68(D20fListElement *element, float height);
extern "C" void d20f_element_property_802bfba4(D20fListElement *element, unsigned property);
extern "C" void d20f_element_position_802bd430(D20fListElement *element, D20fVec3 position);
extern "C" void d20f_element_setup_802bd158(D20fListElement *element);

extern "C" void d20f_list_element_802b8be0(D20fListOwner *self) {
 if (!self->element) {
  D20fListContext *context = self->context;
  float inset = self->scale * 0.5f;
  const D20fVec3 &dimensions = context->dimensions;
  float margin = context->margin;
  float width = dimensions.x - margin - inset;
  float size = context->size;
  if (size == 0.0f) size = d20f_text_size_802b1880(self->text);
  self->element = new D20fListElement;
  d20f_element_interface_802c0c24(self->element, self->interface112);
  d20f_element_length_802bd3cc(self->element, width);
  d20f_element_select_802bd2c4(self->element, self->selection, 0);
  d20f_element_layer_802c0cac(self->element, self->layer);
  d20f_element_value_802bfb2c(self->element, context->value);
  d20f_element_height_802bfb68(self->element, dimensions.y - inset);
  self->element->size = size;
  d20f_element_interface_802bdc88(self->element, self->interface280);
  d20f_element_property_802bfba4(self->element, self->property);
  D20fVec3 position;
  D20fVec3 *p = &position;
  p->x = inset * 1.5f + (0.0f - context->dimensions.x + width);
  p->y = 0.0f;
  p->z = 0.0f;
  d20f_element_position_802bd430(self->element, position);
  d20f_element_setup_802bd158(self->element);
 } else d20f_element_select_802bd2c4(self->element, self->selection, 1);
}
