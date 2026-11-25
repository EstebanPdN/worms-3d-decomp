/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef unsigned int size_t;
struct w3d_registry_cb { char head[24]; void *callback; char middle[6]; unsigned short count; };
extern w3d_registry_cb w3d_registry_8045ee24;
struct w3d_base_4 { int data; };
struct w3d_entry_base { int data; };
extern "C" void fn_8020fd04(w3d_registry_cb *registry, w3d_entry_base *entry);
struct w3d_class_80206ee8 : w3d_base_4, w3d_entry_base {
    char rest[44];
    w3d_class_80206ee8();
    static void *operator new(size_t size);
};
extern w3d_class_80206ee8 *w3d_singleton_804ab9ac;
extern "C" void **fn_8020b648(void);
extern "C" char lbl_804191b0[];
extern "C" int fn_80206e0c(void);
extern "C" void fn_80206de4(void);
typedef void (*W3dPublishFn)(void *manager, char *name, void *object);

extern "C" void w3d_singleton_create_80206d54(void)
{
    w3d_singleton_804ab9ac = new w3d_class_80206ee8;
    fn_8020fd04(&w3d_registry_8045ee24, w3d_singleton_804ab9ac);
    w3d_registry_8045ee24.count++;
    void **manager = fn_8020b648();
    ((W3dPublishFn)((void **)*manager)[24])(manager, lbl_804191b0, w3d_singleton_804ab9ac);
    w3d_registry_8045ee24.callback = (void *)fn_80206e0c;
    fn_80206de4();
}
