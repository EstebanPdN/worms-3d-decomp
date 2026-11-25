// Instancia de un modelo cargado por nombre: una rama de la escena por cada malla del modelo.
#include "native_game.h"

namespace {
template <class T> struct RefArray { w3d_u32 count, capacity; Ptr32<Ptr32<void>> items; };
struct ModelInstance {
    char pad[0xc4];
    Ptr32<void> resource;           // +0xc4
    RefArray<void> instances;       // +0xc8
    RefArray<void> transforms;      // +0xd4
    RefArray<void> materials;       // +0xe0
    char pad2[0xf8 - 0xec];
    GameString name;                // +0xf8
};
struct LoadedModel { char pad[0xbc]; Ptr32<void> resource; };
struct ResourceInfo { char pad[8]; int kind; };
struct SceneNode { char pad[0x30]; Ptr32<void> child; };
const int kKindModel = 6;
const w3d_u32 kFailed = 0x80004005u;
void set_item(Ptr32<void> &slot, void *value) {
    add_reference(value);
    release_if_set(slot.get());
    slot = value;
}
}
extern "C" {
extern GameString A804b06a0;      // Cadena vacía.
extern Ptr32<void> A804ab5fc;     // Cargador de recursos.
extern char A804144f8, A80414940, A80413368, A80413418;
void A80210afc(void *array);
void A80210b90(void *array, w3d_u32 count);
void A80343584();
w3d_u32 A8020b680(void *type);
w3d_u32 A8018ca1c(void *self);
void A8020bcc0(GameString *string, int value);
void A80341588(GameString *string);

// 0x8018d660: si falla, deja el objeto sin modelo llamándose a sí misma con el nombre vacío.
w3d_u32 A8018d660(Ptr32<ModelInstance> self, Ptr32<GameString> name) {
    release_if_set(self->resource.get());
    self->resource = (void *)nullptr;
    A80210afc(&self->materials);
    A80210afc(&self->transforms);
    A80210afc(&self->instances);
    if (!name->header()->length) {
        self->name.assign(A804b06a0);
        return 0;
    }
    self->name.assign(*name);
    Ptr32<void> found{(void *)nullptr};
    const int status = call_virtual<int>(A804ab5fc.get(), 0x88, name.get(), &found, (void *)0xff);
    if (status < 0) {
        release_if_set(found.get());
        return status;
    }
    A80343584();
    LoadedModel *model = (LoadedModel *)found.get();
    if (model) add_reference(model);
    if (model->resource) add_reference(model->resource.get());
    release_if_set(self->resource.get());
    self->resource = model->resource;
    w3d_u32 result = 0;
    auto clear_on_failure = [&] {
        GameString empty;
        A8020bcc0(&empty, 0);
        A8018d660(self, &empty);
        A80341588(&empty);
    };
    if (at<ResourceInfo>(call_virtual(self->resource.get(), 0x20))->kind != kKindModel) {
        clear_on_failure();
        result = kFailed;
    } else {
        const w3d_u32 count = A8018ca1c(self.get());
        A80210b90(&self->materials, count);
        A80210b90(&self->transforms, count);
        A80210b90(&self->instances, count);
        for (w3d_u32 i = 0; i < count; i++) {
            void *branch = g2h(A8020b680(&A804144f8));
            add_reference(branch);
            void *instance = g2h(A8020b680(&A80414940));
            add_reference(instance);
            void *transform = g2h(A8020b680(&A80413368));
            add_reference(transform);
            void *material = g2h(A8020b680(&A80413418));
            add_reference(material);
            set_item(self->instances.items[i], instance);
            set_item(self->transforms.items[i], transform);
            set_item(self->materials.items[i], material);
            SceneNode *node = (SceneNode *)branch;
            void *old = node->child;
            node->child = instance;
            add_reference(instance);
            release_if_set(old);
            call_virtual<void>(transform, 0x18, self->resource.get());
            call_virtual<void>(material, 0x18, transform);
            const int attached = call_virtual<int>(transform, 0x28, branch);
            if (attached < 0) clear_on_failure();
            release_reference(material);
            release_reference(transform);
            release_reference(instance);
            release_reference(branch);
            if (attached < 0) { result = attached; break; }
        }
    }
    release_if_set(model);
    release_if_set(found.get());
    return result;
}
}
