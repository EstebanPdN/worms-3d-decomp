// Descriptores de tipo de los objetos XOM y sus accesos genéricos a propiedades.
#include "native_common.h"

extern "C" {
// Cada descriptor de propiedad tiene una función que llama al acceso de su tipo en el objeto:
// (descriptor, objeto, índice, -, valor). El índice y el valor pasan tal cual, sin el descriptor.
#define PROPERTY_ACCESS(ADDR, OFFSET) \
    w3d_u32 A##ADDR(w3d_u32, Ptr32<void> object, w3d_u32 index, w3d_u32 d, w3d_u32 value, REGS_F) { \
        return call_virtual(object.get(), OFFSET, arg(index), arg(value), arg(d), arg(value), PASS_F); \
    }
PROPERTY_ACCESS(801fe708, 0x2c)
PROPERTY_ACCESS(801fe740, 0x34)
PROPERTY_ACCESS(801fe980, 0x38)
PROPERTY_ACCESS(801fe824, 0x3c)
PROPERTY_ACCESS(801fe85c, 0x3c)
PROPERTY_ACCESS(801febb8, 0x40)
PROPERTY_ACCESS(801fea9c, 0x44)
PROPERTY_ACCESS(801fedf0, 0x48)
PROPERTY_ACCESS(801fecd4, 0x4c)
PROPERTY_ACCESS(801ffbe4, 0x4c)
PROPERTY_ACCESS(801fedb8, 0x58)
PROPERTY_ACCESS(801ff174, 0x58)
PROPERTY_ACCESS(801fec9c, 0x5c)
PROPERTY_ACCESS(801ffbac, 0x5c)
PROPERTY_ACCESS(801ff3d4, 0x60)
PROPERTY_ACCESS(801ff13c, 0x74)
PROPERTY_ACCESS(801ff39c, 0x84)

// Método virtual 0x18: el descriptor de tipo del objeto. Tres copias en el original.
struct TypeDescriptor { Ptr32<const char> name; w3d_u32 parent; w3d_u32 key_data; };
#define GET_TYPE(ADDR) w3d_u32 A##ADDR(Ptr32<void> object, REGS_B) { return call_virtual(object.get(), 0x18, PASS_B); }
GET_TYPE(802001a8)
GET_TYPE(8020017c)
GET_TYPE(80200460)

w3d_u32 A801fff3c(Ptr32<void> object, REGS_B) { return at<TypeDescriptor>(A802001a8(object, b, c, d, e, f, g, h, PASS_FLOATS))->key_data; }
w3d_u32 A801ffea8(Ptr32<void> object, REGS_B) { return at<TypeDescriptor>(A8020017c(object, b, c, d, e, f, g, h, PASS_FLOATS))->name.v; }
}
