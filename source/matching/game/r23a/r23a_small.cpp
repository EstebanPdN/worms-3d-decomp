// Worms 3D GWMP8P rev0. Inferred names; observed layouts are PPC32 only.
// These external objects/functions remain owned by the original image.
extern "C" {
extern unsigned char descriptor_80360b70[];
extern unsigned char descriptor_80360ba0[];
struct ReferenceHeader { void *dispatch; unsigned short references; };
struct PayloadObject;
void payload_operation_800d5028(PayloadObject *);
void payload_prepare_800d308c(PayloadObject *);
void payload_pending_clear_800ccd54(PayloadObject *);
int w3d_r23a_invalid_result_800ccaf0() { return -1; }
void *w3d_r23a_descriptor_800cc77c() { return descriptor_80360b70; }
void *w3d_r23a_descriptor_800cdaa8() { return descriptor_80360ba0; }
// Unsigned 16-bit counter at +4; returns the old value, wraps on store.
unsigned short w3d_r23a_retain_previous_800cc888(ReferenceHeader *object) { return object->references++; }
unsigned short w3d_r23a_retain_previous_800cdbb4(ReferenceHeader *object) { return object->references++; }
void w3d_r23a_payload_forward_800cc75c(PayloadObject *object) { payload_operation_800d5028(object); }
void w3d_r23a_payload_clear_800ccbf4(PayloadObject *object) { payload_pending_clear_800ccd54(object); }
void w3d_r23a_payload_prepare_forward_800cc728(PayloadObject *object) { payload_prepare_800d308c(object); payload_operation_800d5028(object); }
// Float at +64 precedes an embedded member at +68; total object size unknown.
struct ScalarMemberObject { unsigned char unknown[64]; float scalar; unsigned char member[1]; };
void member_query_8012629c(void *);
void w3d_r23a_set_scalar_query_8003e25c(ScalarMemberObject *object, float scalar) { object->scalar = scalar; member_query_8012629c(object->member); }
struct ServiceObject { void *dispatch; };
extern unsigned char dispatch_8040e248[];
extern int active_service_804aa828;
void service_destroy_801628ec(ServiceObject *);
void w3d_r23a_service_shutdown_80029298(ServiceObject *object) { object->dispatch = dispatch_8040e248; active_service_804aa828 = 0; service_destroy_801628ec(object); }
struct ModeObject { unsigned char unknown[84]; int mode; };
void mode_update_8003ed10(ModeObject *);
void w3d_r23a_update_mode_one_8003e370(ModeObject *object) { if (object->mode == 0) goto done; if (object->mode == 1) mode_update_8003ed10(object); done:; }
}
