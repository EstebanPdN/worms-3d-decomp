/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef unsigned int size_t;
struct w3d_registry_cb { char head[24]; void *callback; char middle[6]; unsigned short count; };
extern w3d_registry_cb w3d_registry_804552b0;
struct w3d_base_4 { int data; };
struct w3d_entry_base { int data; };
extern "C" void fn_8020fd04(w3d_registry_cb *registry, w3d_entry_base *entry);
struct w3d_class_80165924 : w3d_base_4, w3d_entry_base {
    char rest[24];
    w3d_class_80165924();
    static void *operator new(size_t size);
};
extern w3d_class_80165924 *w3d_singleton_804ab4ec;
extern "C" void **fn_8020b648(void);
extern "C" char lbl_80411a20[];
extern "C" int fn_801656b4(void);
extern "C" void fn_8016568c(void);
typedef void (*W3dPublishFn)(void *manager, char *name, void *object);

extern "C" void w3d_singleton_create_801655fc(void)
{
    w3d_singleton_804ab4ec = new w3d_class_80165924;
    fn_8020fd04(&w3d_registry_804552b0, w3d_singleton_804ab4ec);
    w3d_registry_804552b0.count++;
    void **manager = fn_8020b648();
    ((W3dPublishFn)((void **)*manager)[24])(manager, lbl_80411a20, w3d_singleton_804ab4ec);
    w3d_registry_804552b0.callback = (void *)fn_801656b4;
    fn_8016568c();
}
