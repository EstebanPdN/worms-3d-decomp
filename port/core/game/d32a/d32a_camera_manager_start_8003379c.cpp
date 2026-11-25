#include "w3d_ptr.h"
#line 1 "d32a_camera_manager_start_8003379c.cpp"
// GWMP8P rev0 0x8003379c. Camera manager start-up: copies the 64-byte view
// matrix from the display, reads Camera.Shake.Magnitude and
// Airstrike.MaxDistance, loads Camera.Free.Pitching, subscribes to 78 cached
// messages with handler slots, creates the fourteen camera modes from their
// pool, appends them to the camera vector, activates them through their
// secondary interface, creates a service by type and hands the orbit
// camera's vectors to the display. Names are inferred from the original
// strings and instructions.
extern "C" Ptr32<unsigned char> storage_allocate_80212fd4(unsigned int);
extern "C" void storage_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> storage_copy_802eee50(Ptr32<void>, Ptr32<const void>, ...);
static inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned int &smaller(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
struct CameraBase;
struct Camera;
struct CameraVector {
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
    void push(Ptr32<CameraBase> const &value) {
        if (end == capacity) {
            unsigned int used = end - begin;
            int next = used + 1;
            int grown = used + (used >> 1);
            unsigned int allocated = larger(next, grown) * 4;
            Ptr32<unsigned char> fresh = storage_allocate_80212fd4(allocated);
            if (begin) {
                storage_copy_802eee50(fresh, begin, smaller(allocated, used));
                storage_release_802134fc(begin);
            }
            begin = fresh;
            end = fresh + used;
            capacity = fresh + allocated;
        }
        *(Ptr32<Ptr32<CameraBase>>)end = value;
        end += 4;
    }
};
struct CameraInterface { Ptr32<void> unknown00[6]; Ptr32<void (Ptr32<Camera>)> activate; };
struct CameraBase { char unknown00[4]; };
struct Camera : CameraBase {
    float vector4[3] __attribute__((aligned(__alignof__(CameraBase))));          /* +4 */
    float vector16[3];         /* +16 */
    float vector28[3];         /* +28 */
    char unknown40[32];
    Ptr32<CameraInterface> secondary; /* +72 */
};
struct Matrix { float m[16]; };
struct Display;
struct DisplayVtable {
    Ptr32<void> unknown00[8];
    Ptr32<Ptr32<Matrix> (Ptr32<Display>)> view;            /* +32 */
    Ptr32<void> unknown36[2];
    Ptr32<void (Ptr32<Display>, Ptr32<float>)> setVector44; /* +44 */
    Ptr32<int (Ptr32<Display>, Ptr32<float>)> setVector48; /* +48 */
    Ptr32<void (Ptr32<Display>, Ptr32<float>)> setVector52; /* +52 */
};
struct Display { Ptr32<DisplayVtable> vtable; };
struct GameState { char unknown00[48]; Ptr32<Display> display; };
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Handle {
    Ptr32<Object> value;
    Handle() {}
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
struct PropertyKey { Ptr32<const char> name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct CameraManager {
    char unknown00[20];
    unsigned id;               /* +20 */
    char unknown24[84];
    char slot108[4];
    char slot112[4];
    char slot116[4];
    char slot120[4];
    char slot124[4];
    char slot128[4];
    char slot132[4];
    char slot136[4];
    char slot140[4];
    char slot144[4];
    char slot148[4];
    char slot152[4];
    char slot156[4];
    char slot160[4];
    char slot164[4];
    char slot168[4];
    char slot172[4];
    char slot176[4];
    char slot180[4];
    char slot184[4];
    char slot188[4];
    char slot192[4];
    char slot196[4];
    char slot200[4];
    char slot204[4];
    char slot208[4];
    char slot212[4];
    char slot216[4];
    char slot220[4];
    char slot224[4];
    char slot228[4];
    char slot232[4];
    char slot236[4];
    char slot240[4];
    char slot244[4];
    char slot248[4];
    char slot252[4];
    char slot256[4];
    char slot260[4];
    char slot264[4];
    char slot268[4];
    char slot272[4];
    char slot276[4];
    char slot280[4];
    char slot284[4];
    char slot288[4];
    char slot292[4];
    char slot296[4];
    char slot300[4];
    char slot304[4];
    char slot308[4];
    int unknown312;            /* +312 */
    CameraVector cameras;      /* +316 */
    char unknown328[292];
    char slot620[4];
    char slot624[4];
    char slot628[4];
    char slot632[4];
    char slot636[4];
    char slot640[4];
    char slot644[4];
    char slot648[4];
    char slot652[4];
    char slot656[4];
    char slot660[4];
    char slot664[4];
    char slot668[4];
    char slot672[4];
    char slot676[4];
    char slot680[4];
    char slot684[4];
    char slot688[4];
    char slot692[4];
    char slot696[4];
    char slot700[4];
    char slot704[4];
    char slot708[4];
    char slot712[4];
    char slot716[4];
    char slot720[4];
    char slot724[4];
    char unknown728[20];
    Ptr32<Object> airstrikeMaxDistance; /* +748 */
    Ptr32<Object> cameraShakeMagnitude; /* +752 */
    char unknown756[68];
    Ptr32<Object> cameraFreePitching; /* +824 */
    char unknown828[44];
    Matrix view;               /* +872 */
};
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<Object> w3d_identity_80342a78(Ptr32<Object>);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_subscribe_80162024(Ptr32<CameraManager>, const unsigned short &, Ptr32<void>);
extern "C" Ptr32<void> w3d_heap_allocate_802098d8(Ptr32<void>, unsigned int);
extern "C" Ptr32<void> w3d_type_lookup_8020b680(Ptr32<void>);
extern "C" Ptr32<void> w3d_create_80164514(Ptr32<void>, Ptr32<void>, unsigned);
extern Ptr32<GameState> w3d_game_state_804b1788;
extern Ptr32<void> w3d_service_804b178c;
struct CameraPool { int head; };
extern CameraPool w3d_camera_pool_804b0044;
extern unsigned char w3d_type_80410fb0[];
extern MessageCache w3d_message_804acd84, w3d_message_804acd8c, w3d_message_804acd94, w3d_message_804acd9c, w3d_message_804acda4, w3d_message_804acdac, w3d_message_804acdb4, w3d_message_804acdbc, w3d_message_804acdc4, w3d_message_804acdcc, w3d_message_804acdd4, w3d_message_804acddc, w3d_message_804acde4, w3d_message_804acdec, w3d_message_804acdf4, w3d_message_804acdfc, w3d_message_804ace04, w3d_message_804ace0c, w3d_message_804ace14, w3d_message_804ace1c, w3d_message_804ace24, w3d_message_804ace2c, w3d_message_804ace34, w3d_message_804ace3c, w3d_message_804ace44, w3d_message_804ace4c, w3d_message_804ace54, w3d_message_804ace5c, w3d_message_804ace64, w3d_message_804ace6c, w3d_message_804ace74, w3d_message_804ace7c, w3d_message_804ace84, w3d_message_804ace8c, w3d_message_804ace94, w3d_message_804ace9c, w3d_message_804acea4, w3d_message_804aceac, w3d_message_804aceb4, w3d_message_804acebc, w3d_message_804acec4, w3d_message_804acecc, w3d_message_804aced4, w3d_message_804acedc, w3d_message_804acee4, w3d_message_804aceec, w3d_message_804acef4, w3d_message_804acefc, w3d_message_804acf04, w3d_message_804acf0c, w3d_message_804acf14, w3d_message_804acf1c, w3d_message_804acf34, w3d_message_804acf3c, w3d_message_804acf44, w3d_message_804acf4c, w3d_message_804acf54, w3d_message_804acf5c, w3d_message_804acf64, w3d_message_804acf6c, w3d_message_804acf74, w3d_message_804acf7c, w3d_message_804acf84, w3d_message_804acf8c, w3d_message_804acf94, w3d_message_804acf9c, w3d_message_804acfa4, w3d_message_804acfac, w3d_message_804acfb4, w3d_message_804acfbc, w3d_message_804acfc4, w3d_message_804acfcc, w3d_message_804acfd4, w3d_message_804acfdc, w3d_message_804acfe4, w3d_message_804acfec, w3d_message_804acff4, w3d_message_804ad00c;
extern "C" Ptr32<Camera> w3d_camera_ctor_8009e024(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<Camera> w3d_camera_ctor_800520f4(Ptr32<void>, Ptr32<const char>, int);
extern "C" Ptr32<Camera> w3d_camera_ctor_800ac588(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<Camera> w3d_camera_ctor_800d6b44(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<Camera> w3d_camera_ctor_8006f5dc(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<Camera> w3d_camera_ctor_80067978(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<Camera> w3d_camera_ctor_80092d34(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<Camera> w3d_camera_ctor_800e7278(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<Camera> w3d_camera_ctor_8011f66c(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<Camera> w3d_camera_ctor_80072460(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<Camera> w3d_camera_ctor_800372b0(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<Camera> w3d_camera_ctor_800cc6d0(Ptr32<void>, Ptr32<const char>, int);
extern "C" Ptr32<Camera> w3d_camera_ctor_800af1e0(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<Camera> w3d_camera_ctor_800a8348(Ptr32<void>, Ptr32<const char>, int);
extern "C" char w3d_string_803732a8[]; /* "Camera.Shake.Magnitude" */
extern "C" char w3d_string_80373308[]; /* "Airstrike.MaxDistance" */
extern "C" char w3d_string_80373320[]; /* "Camera.Free.Pitching" */
extern "C" char w3d_string_80373338[];
extern "C" char w3d_string_80373260[];
extern "C" char w3d_string_80373340[];
extern "C" char w3d_string_80373348[];
extern "C" char w3d_string_80373350[];
extern "C" char w3d_string_80373358[];
extern "C" char w3d_string_80373360[];
extern "C" char w3d_string_803732c0[];
extern "C" char w3d_string_8037336c[];
extern "C" char w3d_string_8037328c[];
extern "C" char w3d_string_80373374[];
extern "C" char w3d_string_8037337c[];
extern "C" char w3d_string_80373384[];
extern "C" char w3d_string_80373394[];

inline void GetResource(Ptr32<const char> name, Ptr32<Ptr32<Object>> out)
{
    PropertyKey key;
    key.name = name;
    w3d_resource_property_800fc1b0(&key, out);
}

inline void LoadResource(Handle &h, Ptr32<const char> name, Ptr32<Object> &slot)
{
    PropertyKey key;
    key.name = name;
    h.value = 0;
    w3d_resource_property_800fc1b0(&key, &h.value);
    Ptr32<Object> object = w3d_identity_80342a78(h.value);
    if (object) object->vtable->retain(object);
    if (slot) slot->vtable->release(slot);
    slot = object;
}

extern "C" void w3d_d32a_camera_manager_start_8003379c(Ptr32<CameraManager> self)
{
    Handle handle;
    self->view = *w3d_game_state_804b1788->display->vtable->view(w3d_game_state_804b1788->display);
    GetResource(w3d_string_803732a8, &self->cameraShakeMagnitude);
    GetResource(w3d_string_80373308, &self->airstrikeMaxDistance);
    LoadResource(handle, w3d_string_80373320, self->cameraFreePitching);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acd84, 1), self->slot108);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acd8c, 1), self->slot112);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acd94, 1), self->slot116);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acd9c, 1), self->slot120);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acda4, 1), self->slot124);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acdac, 1), self->slot128);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acdb4, 1), self->slot132);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acdbc, 1), self->slot136);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acde4, 1), self->slot140);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acdec, 1), self->slot144);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acdf4, 1), self->slot148);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acdfc, 1), self->slot152);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acdc4, 1), self->slot172);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acdcc, 1), self->slot176);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acdd4, 1), self->slot180);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acddc, 1), self->slot184);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace04, 1), self->slot192);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace0c, 1), self->slot196);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace14, 1), self->slot200);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace1c, 1), self->slot204);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace24, 1), self->slot208);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace2c, 1), self->slot212);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace34, 1), self->slot216);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace3c, 1), self->slot220);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace44, 1), self->slot620);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace4c, 1), self->slot624);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace54, 1), self->slot628);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace5c, 1), self->slot632);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace64, 1), self->slot636);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace6c, 1), self->slot640);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace74, 1), self->slot644);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace7c, 1), self->slot648);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acea4, 1), self->slot652);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aceac, 1), self->slot656);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aceb4, 1), self->slot660);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acebc, 1), self->slot664);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace84, 1), self->slot668);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace8c, 1), self->slot672);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace94, 1), self->slot676);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ace9c, 1), self->slot680);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acec4, 1), self->slot684);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acecc, 1), self->slot688);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aced4, 1), self->slot692);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acedc, 1), self->slot696);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acee4, 1), self->slot700);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aceec, 1), self->slot704);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acef4, 1), self->slot708);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acefc, 1), self->slot712);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf04, 1), self->slot716);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf0c, 1), self->slot720);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf14, 1), self->slot724);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf1c, 1), self->slot188);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf64, 1), self->slot156);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf7c, 1), self->slot160);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf6c, 1), self->slot164);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf74, 1), self->slot168);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf44, 1), self->slot280);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf54, 1), self->slot284);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf5c, 1), self->slot288);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf4c, 1), self->slot292);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf34, 1), self->slot232);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf3c, 1), self->slot236);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf94, 1), self->slot252);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf9c, 1), self->slot256);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acfa4, 1), self->slot260);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acfb4, 1), self->slot244);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acfbc, 1), self->slot248);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf84, 1), self->slot240);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acfcc, 1), self->slot228);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acfc4, 1), self->slot224);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acfd4, 1), self->slot264);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acfdc, 1), self->slot268);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acfe4, 1), self->slot272);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acfac, 1), self->slot276);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acf8c, 1), self->slot296);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acfec, 1), self->slot300);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acff4, 1), self->slot304);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad00c, 1), self->slot308);
    self->unknown312 = 0;
    Ptr32<Camera> head = w3d_camera_ctor_8009e024(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 112), w3d_string_80373338);
    Ptr32<Camera> standard = w3d_camera_ctor_800520f4(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 212), w3d_string_80373260, 2);
    Ptr32<Camera> jetpack = w3d_camera_ctor_800ac588(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 192), w3d_string_80373340);
    Ptr32<Camera> orbit = w3d_camera_ctor_800d6b44(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 108), w3d_string_80373348);
    Ptr32<Camera> flyCam = w3d_camera_ctor_8006f5dc(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 112), w3d_string_80373350);
    Ptr32<Camera> fallCam = w3d_camera_ctor_80067978(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 96), w3d_string_80373358);
    Ptr32<Camera> girder = w3d_camera_ctor_80092d34(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 220), w3d_string_80373360);
    Ptr32<Camera> path = w3d_camera_ctor_800e7278(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 88), w3d_string_803732c0);
    Ptr32<Camera> track = w3d_camera_ctor_8011f66c(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 180), w3d_string_8037336c);
    Ptr32<Camera> free = w3d_camera_ctor_80072460(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 96), w3d_string_8037328c);
    Ptr32<Camera> chase = w3d_camera_ctor_800372b0(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 224), w3d_string_80373374);
    Ptr32<Camera> ninja = w3d_camera_ctor_800cc6d0(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 208), w3d_string_8037337c, 17);
    Ptr32<Camera> jetpackGround = w3d_camera_ctor_800af1e0(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 212), w3d_string_80373384);
    Ptr32<Camera> blimp = w3d_camera_ctor_800a8348(w3d_heap_allocate_802098d8(&w3d_camera_pool_804b0044, 184), w3d_string_80373394, 3);
    self->cameras.push(standard);
    self->cameras.push(head);
    self->cameras.push(jetpack);
    self->cameras.push(orbit);
    self->cameras.push(girder);
    self->cameras.push(flyCam);
    self->cameras.push(fallCam);
    self->cameras.push(chase);
    self->cameras.push(ninja);
    self->cameras.push(path);
    self->cameras.push(track);
    self->cameras.push(jetpackGround);
    self->cameras.push(free);
    self->cameras.push(blimp);
    head->secondary->activate(head);
    standard->secondary->activate(standard);
    jetpack->secondary->activate(jetpack);
    orbit->secondary->activate(orbit);
    girder->secondary->activate(girder);
    flyCam->secondary->activate(flyCam);
    fallCam->secondary->activate(fallCam);
    path->secondary->activate(path);
    track->secondary->activate(track);
    free->secondary->activate(free);
    ninja->secondary->activate(ninja);
    jetpackGround->secondary->activate(jetpackGround);
    blimp->secondary->activate(blimp);
    Ptr32<void> type = w3d_type_lookup_8020b680(w3d_type_80410fb0);
    w3d_create_80164514(w3d_service_804b178c, type, self->id);
    Ptr32<Display> display = w3d_game_state_804b1788->display;
    display->vtable->setVector44(display, orbit->vector4);
    display->vtable->setVector48(display, orbit->vector16);
    display->vtable->setVector52(display, orbit->vector28);
}


