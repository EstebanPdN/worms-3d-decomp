/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef unsigned int size_t;
struct w3d_registry_cb { char head[24]; void *callback; char middle[6]; unsigned short count; };
extern w3d_registry_cb w3d_registry_80457014;
struct w3d_base_4 { int data; };
struct w3d_entry_base { int data; };
extern "C" void fn_8020fd04(w3d_registry_cb *registry, w3d_entry_base *entry);
struct w3d_class_8017b9c8 : w3d_base_4, w3d_entry_base {
    char rest[9844];
    w3d_class_8017b9c8();
    static void *operator new(size_t size);
};
extern w3d_class_8017b9c8 *w3d_singleton_804ab600;
extern "C" void **fn_8020b648(void);
extern "C" char lbl_80412790[];
extern "C" int fn_8017b8ec(void);
extern "C" void fn_8017b8c4(void);
typedef void (*W3dPublishFn)(void *manager, char *name, void *object);

extern "C" void w3d_singleton_create_8017b834(void)
{
    w3d_singleton_804ab600 = new w3d_class_8017b9c8;
    fn_8020fd04(&w3d_registry_80457014, w3d_singleton_804ab600);
    w3d_registry_80457014.count++;
    void **manager = fn_8020b648();
    ((W3dPublishFn)((void **)*manager)[24])(manager, lbl_80412790, w3d_singleton_804ab600);
    w3d_registry_80457014.callback = (void *)fn_8017b8ec;
    fn_8017b8c4();
}
