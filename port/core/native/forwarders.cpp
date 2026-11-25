// Funciones del juego que solo reenvían a otra, o que añaden un paso mínimo. Los argumentos que no se nombran llegan intactos:
// ver native_common.h.
#include "native_common.h"

// Reenvíos puros: en el original son funciones propias, normalmente una sobrecarga o un miembro de una clase derivada.
#define FORWARD(ADDR, TARGET) void A##TARGET(); w3d_u32 A##ADDR(REGS_A) { return ((AllRegs)A##TARGET)(PASS_A); }
#define FORWARD_RETURN_ZERO(ADDR, TARGET) void A##TARGET(); w3d_u32 A##ADDR(REGS_A) { ((AllRegs)A##TARGET)(PASS_A); return 0; }

extern "C" {
FORWARD(8000cfe4, 8000d004)
FORWARD(80010898, 80010630)
FORWARD(8001528c, 8001523c)
FORWARD(80017848, 80017380)
FORWARD(80017a70, 80017a04)
FORWARD(80048fac, 800490bc)
FORWARD(80052340, 800d5028)
FORWARD(800df684, 800e0400)
FORWARD(80118268, 800d7788)
FORWARD(80139994, 8013e3d4)
FORWARD(8016293c, 8015fb34)
FORWARD(80166ff8, 8016703c)
FORWARD(801689a0, 801a38c8)
FORWARD(801a3628, 801a2350)
FORWARD(80175974, 8034bf50)
FORWARD(80175994, 8034c148)
FORWARD(801759d4, 8034c538)
FORWARD(80175a14, 8034c928)
FORWARD(80203fb8, 80204760)   // escribe un entero de longitud variable en el flujo
FORWARD(80204448, 802047e0)   // transferencia del flujo
FORWARD(80204740, 802047e0)
FORWARD(802044a8, 8035bc90)
FORWARD(802044c8, 8035bc90)
FORWARD(80204530, 8035bd50)
FORWARD(802abfdc, 80316270)
FORWARD(80299a74, 8029d578)

FORWARD_RETURN_ZERO(800d5494, 800d56bc)

// Fin de un guion: cada tipo de objeto tiene su propio envoltorio, que siempre devuelve 0.
FORWARD_RETURN_ZERO(801b5328, 801e8d9c)
FORWARD_RETURN_ZERO(801b705c, 801e8d9c)
FORWARD_RETURN_ZERO(801b7e8c, 801e8d9c)
FORWARD_RETURN_ZERO(801b884c, 801e8d9c)
FORWARD_RETURN_ZERO(801b89b4, 801e8d9c)
FORWARD_RETURN_ZERO(801b8b1c, 801e8d9c)
FORWARD_RETURN_ZERO(801b8c84, 801e8d9c)
FORWARD_RETURN_ZERO(801b8dec, 801e8d9c)
FORWARD_RETURN_ZERO(801be070, 801e8d9c)
FORWARD_RETURN_ZERO(801bf0c4, 801e8d9c)
FORWARD_RETURN_ZERO(801c155c, 801e8d9c)
FORWARD_RETURN_ZERO(801cb4b4, 801e8d9c)
FORWARD_RETURN_ZERO(801ce318, 801e8d9c)
FORWARD_RETURN_ZERO(801ea44c, 801e8d9c)
FORWARD_RETURN_ZERO(80226d44, 801e8d9c)

// El flotante del original va entre enteros, pero los bancos son independientes.
FORWARD(801759b4, 8034c340)

// Devuelven un valor fijo, siempre tras hacer lo mismo.
void A8012458c();
w3d_u32 A801242bc(REGS_A) { ((AllRegs)A8012458c)(PASS_A); return 0x14; }
void A8008ed18();
w3d_u32 A800b9810(w3d_u32, w3d_u32, REGS_C) { ((AllRegs)A8008ed18)((void *)1, (void *)10, PASS_C); return 0; }
void A800fcec8();
w3d_u32 A800fcea0(w3d_u32, w3d_u32, REGS_C) { return ((AllRegs)A800fcec8)((void *)0xffffffffu, (void *)0x3c, PASS_C); }

// Los paneles con un selector giratorio en +0x1c.
void A802b0668();
#define PANEL_STEP(ADDR) w3d_u32 A##ADDR(Ptr32<char> panel, REGS_B) { ((AllRegs)A802b0668)((panel + 0x1c).get(), PASS_B); return 0; }
PANEL_STEP(8025f524)
PANEL_STEP(80285b00)
PANEL_STEP(802a3030)
PANEL_STEP(802ba59c)

// Objetos con un miembro en un desplazamiento fijo y un método de ese miembro.
#define MEMBER_CALL(ADDR, MEMBER, OFFSET) \
    w3d_u32 A##ADDR(Ptr32<char> self, REGS_B) { return call_virtual(((Ptr32<void> *)(self.get() + MEMBER))->get(), OFFSET, PASS_B); }
MEMBER_CALL(800a14c4, 0x24, 0x58)
MEMBER_CALL(8015cabc, 0x44, 0x48)
MEMBER_CALL(8015cd34, 0x44, 0x50)
MEMBER_CALL(8015cd04, 0x44, 0x54)
MEMBER_CALL(8015c960, 0x44, 0x88)
MEMBER_CALL(80160e34, 0x1c, 0x44)
MEMBER_CALL(80181d00, 0xc4, 0x34)
MEMBER_CALL(8019fe48, 0x14, 0x24)
MEMBER_CALL(802081c8, 0x14, 0x24)
MEMBER_CALL(80208298, 0x14, 0x14)

w3d_u32 A801817e0(Ptr32<char> self, REGS_B) { call_virtual(((Ptr32<void> *)(self.get() + 0xc4))->get(), 0x3c, PASS_B); return 0; }

// Contador y siguiente paso del generador en +0x5c y +0x60.
struct Stepper { char pad[0x5c]; w3d_u32 steps; Ptr32<void> generator; };
w3d_u32 A8015cc24(Ptr32<Stepper> self, REGS_B) { self->steps++; return call_virtual(self->generator.get(), 0x28, PASS_B); }

// Flujo de lectura y escritura en +0x14.
struct Serializer { char pad[0x14]; Ptr32<void> stream; };
w3d_u32 A80201400(Ptr32<Serializer> self, w3d_u32 value, w3d_u32, w3d_u32, REGS_E) { return call_virtual(self->stream.get(), 0x14, arg(value), (void *)1, (void *)0, PASS_E); }
w3d_u32 A802025a8(Ptr32<Serializer> self, w3d_u32 value, w3d_u32 size, w3d_u32, REGS_E) { return call_virtual(self->stream.get(), 0x14, arg(value), arg(size), (void *)0, PASS_E); }
w3d_u32 A802047ac(Ptr32<Serializer> self, w3d_u32 value, w3d_u32 size, w3d_u32, REGS_E) { return call_virtual(self->stream.get(), 0x18, arg(value), arg(size), (void *)0, PASS_E); }

// Quita el indicador 4 de los modos y delega en el método 0x14 del propio objeto.
w3d_u32 A802185c8(Ptr32<void> self, w3d_u32 value, w3d_u32 flags, REGS_D) { return call_virtual(self.get(), 0x14, arg(value), arg(flags & ~4u), PASS_D); }

// Referencias a guiones: valor de Lua guardado en el registro (LUA_REGISTRYINDEX = -10000).
void A802ce30c();
struct ScriptOwner { char pad[0x18]; int reference_a; int reference_b; };
w3d_u32 A8019fdd8(Ptr32<ScriptOwner> self, REGS_B) {
    void *L = arg(A8019fe48(Ptr32<char>(self), b, c, d, e, f, g, h, PASS_FLOATS));
    return ((w3d_u32 (*)(void *, int, int))A802ce30c)(L, -10000, self->reference_a);
}
w3d_u32 A8019fe10(Ptr32<ScriptOwner> self, REGS_B) {
    void *L = arg(A8019fe48(Ptr32<char>(self), b, c, d, e, f, g, h, PASS_FLOATS));
    return ((w3d_u32 (*)(void *, int, int))A802ce30c)(L, -10000, self->reference_b);
}

// Tablas secundarias en mitad del objeto (herencia múltiple): el método recibe el objeto entero.
struct WithSecondaryTable { char pad[0x48]; w3d_u32 table; };
w3d_u32 A8015a6b8(Ptr32<WithSecondaryTable> self, REGS_B) { return call_in_table(self.get(), self->table, 0x18, PASS_B); }

// Asas: {objeto}. Lectura y escritura a través del objeto apuntado.
struct Handle { Ptr32<void> object; };
#define HANDLE_READ(ADDR) w3d_u32 A##ADDR(Ptr32<Handle> self, w3d_u32 value, w3d_u32, REGS_D) { return call_virtual(self->object.get(), 0x4c, arg(value), (void *)0, PASS_D); }
#define HANDLE_WRITE(ADDR) w3d_u32 A##ADDR(Ptr32<Handle> self, Ptr32<void> target, w3d_u32, REGS_D) { return call_virtual(target.get(), 0x5c, self->object.get(), (void *)0, PASS_D); }
HANDLE_READ(8025ee60)
HANDLE_READ(802af220)
HANDLE_READ(802bbc90)
HANDLE_WRITE(8025ee94)
HANDLE_WRITE(802af254)
HANDLE_WRITE(802bbcc4)
w3d_u32 A8025f064(Ptr32<Handle> self, REGS_B) { return call_virtual(self->object.get(), 0x58, PASS_B); }
w3d_u32 A80355a14(Ptr32<Handle> self, REGS_B) { return call_virtual(self->object.get(), 0x10, PASS_B); }

// Pequeños accesos a campos del resultado de otra función.
w3d_u32 A800fc6dc(void *);
w3d_u32 A80174074(void *);
w3d_u32 A800153dc(Ptr32<void> self) { return *at<w3d_u32>(A800fc6dc(self.get()) + 0xdc); }
w3d_u32 A80015564(Ptr32<void> self) { return *at<w3d_u32>(A800fc6dc(self.get()) + 0x8c); }
w3d_u32 A80015588(Ptr32<void> self) { return A800fc6dc(self.get()) + 0x50; }
w3d_u32 A80174050(Ptr32<void> self) { return *at<w3d_u32>(A80174074(self.get()) + 0x3c); }

// Pone a cero un contador global y delega.
extern w3d_u32 A804abc0c;
void A8029d07c();
w3d_u32 A802975f8(REGS_A) { A804abc0c = 0; return ((AllRegs)A8029d07c)(PASS_A); }

// Reloj de juego: puntero a función que instala el arranque.
extern w3d_u32 A804b17b4;
w3d_u32 A801264fc(REGS_A) { return ((AllRegs)g2h(A804b17b4))(PASS_A); }

// Mundo: método 0x8c del gestor en +0x74.
struct World { char pad[0x74]; Ptr32<void> manager; };
extern Ptr32<World> A804b17ec;
w3d_u32 A8015ae3c(w3d_u32 value, w3d_u32, REGS_C) { return call_virtual(A804b17ec->manager.get(), 0x8c, arg(value), PASS_C); }

// Compacta el montón indicado por el asa.
void A80209720();
w3d_u32 A80209968(Ptr32<w3d_u32> heap, REGS_B) { return ((AllRegs)A80209720)(arg(*heap), PASS_B); }
extern w3d_u32 A804b00dc;
w3d_u32 A80167018(w3d_u32, REGS_B) { return A80209968(&A804b00dc, b, c, d, e, f, g, h, PASS_FLOATS); }

// Método del objeto global en 0x804aaecc.
extern w3d_u32 A804aaecc;
void A800e58fc();
w3d_u32 A80107a90(w3d_u32, w3d_u32, REGS_C) { return ((AllRegs)A800e58fc)(arg(A804aaecc), (void *)0, PASS_C); }

// Devuelve 1 si el descriptor lleva el indicador 4 o 0x20; si no, pregunta al objeto. A03: los indicadores son un byte en crudo en +7.
struct DescriptorHeader { char pad[7]; uint8_t flags; };
struct Described { Ptr32<DescriptorHeader> descriptor; w3d_u32 secondary_table; };
w3d_u32 A801eb0b0(Ptr32<Described> self, REGS_B) {
    const uint8_t flags = self->descriptor->flags;
    if ((flags & 4) || (flags & 0x20)) return 1;
    return call_in_table(self.get(), self->secondary_table, 0x18, PASS_B);
}

// Tras el constructor base, marca el objeto como inicializado.
void A80185af0();
struct Initialized { char pad[0xa4]; w3d_u32 initialized; };
w3d_u32 A80179aec(Ptr32<Initialized> self, REGS_B) {
    ((AllRegs)A80185af0)(self.get(), PASS_B);
    self->initialized = 1;
    return 0;
}

// Tabla de 20 filas de 16 B en 0x80431c80: suma de la primera columna.
struct WeightRow { int weight; w3d_u32 rest[3]; };
extern WeightRow A80431c80[20];
int A8008da24() {
    int sum = 0;
    for (const WeightRow &row : A80431c80) sum += row.weight;
    return sum;
}

// Vacía una entrada: conserva los 21 bits bajos de la primera palabra y restaura el valor por defecto.
struct PerfEntry { w3d_u32 bits; w3d_u32 value; w3d_u32 a, b, c; };
extern w3d_u32 A80373c20;
Ptr32<PerfEntry> A80343748(Ptr32<PerfEntry> entry) {
    entry->c = 0;
    entry->bits &= 0x1fffff;
    entry->value = A80373c20;
    entry->a = entry->b = 0;
    return entry;
}
}
