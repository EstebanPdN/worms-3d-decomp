// Cola de temporizadores del motor (0x8034af90). Cada grupo tiene un montículo de eventos por tiempo, una lista de identificadores
// libres y la tabla de manejadores. En cada pasada se atiende el evento más próximo de todos los grupos que no pase del límite.
#include "native_common.h"

namespace {
struct TimerEvent { w3d_u32 id; w3d_u32 time; };
// Vector de STLport: {inicio, fin, asignador vacío, capacidad}. El comparador va detrás, en un byte.
template <class T> struct Vector {
    Ptr32<T> begin, end;
    w3d_u32 allocator;
    Ptr32<T> capacity;
    int size() const { return (int)(end.v - begin.v) / (int)sizeof(T); }
};
struct EventHeap : Vector<TimerEvent> { uint8_t compare; };
struct TimerSlot {
    char pad[0xc];
    Ptr32<void> handler;   // +0x0c
    char pad2[0x14 - 0x10];
    w3d_u32 id;            // +0x14
    char pad3[0x24 - 0x18];
};
struct TimerGroup {
    Ptr32<EventHeap> heap;
    Ptr32<Vector<w3d_u32>> finished;
    Ptr32<Ptr32<TimerSlot>> slots;
};
struct EngineContext { char pad[0x38]; w3d_u32 quit; w3d_u32 in_tick; };
const w3d_u32 kNoEvent = 0xffffffffu;
}
extern "C" {
w3d_u32 A80165254();
void A8034a7fc(void *begin, void *end, void *compare);  // pop_heap
void A8034a400(void *begin, void *end, void *compare);  // push_heap
void A8034b3f8(void *slots, w3d_u32 time);
void A8034b408(void *slots, w3d_u32 time);
w3d_u32 A80212fd4(w3d_u32);
w3d_u32 A803413d8(w3d_u32);
void A802134fc(void *);
void A801651e4();
extern w3d_u32 A804ab4d8, A804b178c;
}
namespace {
inline EngineContext *engine() { return at<EngineContext>(A80165254()); }
inline w3d_u32 allocate(w3d_u32 bytes) {
    const w3d_u32 p = A80212fd4(bytes);
    return p ? p : A803413d8(bytes);
}
// push_back con crecimiento al doble (mínimo 1).
template <class T> void push_back(Vector<T> *v, const T &value) {
    if (v->end.v != v->capacity.v) {
        *v->end.get() = value;
        v->end.v += sizeof(T);
        return;
    }
    const int size = v->size();
    const int count = size + (size < 1 ? 1 : size);
    const w3d_u32 bytes = count * sizeof(T);
    const w3d_u32 storage = count ? allocate(bytes) : 0;
    T *out = (T *)g2h(storage);
    for (const T *in = v->begin.get(); in != v->end.get(); in++) *out++ = *in;
    *out++ = value;
    if (v->begin) A802134fc(v->begin.get());
    v->begin.v = storage;
    v->end.v = h2g(out);
    v->capacity.v = storage + bytes;
}
int next_group(const TimerGroup *groups, w3d_u32 count, w3d_u32 limit) {
    int best = 3;
    w3d_u32 best_time = kNoEvent;
    for (w3d_u32 i = 0; i < count; i++) {
        const EventHeap *heap = groups[i].heap;
        if (heap->end.v == heap->begin.v) continue;
        const w3d_u32 time = heap->begin->time;
        if (time <= limit && time < best_time) {
            best_time = time;
            best = i;
        }
    }
    return best;
}
}
extern "C" w3d_u32 A8034af90(Ptr32<TimerGroup> groups, w3d_u32 count, w3d_u32 limit) {
    engine()->in_tick = 1;
    while (!engine()->quit) {
        const int index = next_group(groups, count, limit);
        if (index == 3) break;
        TimerGroup *group = &groups[index];
        EventHeap *heap = group->heap;
        const TimerEvent event = *heap->begin;
        uint8_t compare = heap->compare;
        A8034a7fc(heap->begin.get(), heap->end.get(), &compare);
        heap->end.v -= sizeof(TimerEvent);

        TimerSlot *slot = nullptr;
        if (event.id != kNoEvent) {
            TimerSlot *candidate = group->slots->get() + (event.id & 0xfff);
            if (candidate->id == event.id) slot = candidate;
        }
        if (slot) {
            A8034b3f8(group->slots.get(), event.time);
            const w3d_u32 delay = call_virtual(slot->handler.get(), 0x20, arg(event.time));
            if (engine()->quit) {
                limit = event.time;
                A8034b408(group->slots.get(), event.time);
            }
            if (delay == 0) {
                push_back(group->finished.get(), event.id);
            } else if (delay != kNoEvent) {
                const TimerEvent next = {event.id, delay + event.time};
                push_back(static_cast<Vector<TimerEvent> *>(heap), next);
                compare = heap->compare;
                A8034a400(heap->begin.get(), heap->end.get(), &compare);
            }
        }
        if (A804ab4d8) ((void (*)(void *))A801651e4)(arg(A804b178c));
    }
    engine()->in_tick = 0;
    return h2g(engine());
}

// 0x8016393c: un paso del motor. Aplica los cambios pedidos, atiende los temporizadores hasta el instante dado y da otra oportunidad
// a los que han terminado: con tiempo de cuadro redondeado a múltiplos de 20 ms, los dos grupos de tareas de cuadro.
namespace {
struct PendingChange { w3d_u32 target_and_flags; w3d_u32 value; };
struct ChangeList { Ptr32<PendingChange> begin; w3d_u32 pad; Ptr32<PendingChange> end; };
struct EngineState {
    char pad[4];
    w3d_u32 base_time;        // +4
    char pad2[0x18 - 8];
    Ptr32<ChangeList> pending;  // +0x18
    char pad3[0x20 - 0x1c];
    w3d_u32 frame_time;       // +0x20
    w3d_u32 idle_since;       // +0x24
    TimerGroup groups[3];     // +0x28, +0x34, +0x40
    char frame_end[1];        // +0x4c
};
struct Application { char pad[0x30]; w3d_u32 frame_time; w3d_u32 idle_since; };
// Lista de tareas de un grupo: las que siguen vivas se quedan; las demás se quitan cambiándolas por la última. Una que devuelve
// un retardo pasa al montículo.
void run_finished(TimerGroup *group, w3d_u32 now) {
    Vector<w3d_u32> *list = group->finished;
    if (!list) return;
    w3d_u32 index = 0;
    while (list->begin.v + index * 4 != list->end.v) {
        const w3d_u32 id = list->begin[index];
        TimerSlot *slot = nullptr;
        if (id != kNoEvent) {
            TimerSlot *candidate = group->slots->get() + (id & 0xfff);
            if (candidate->id == id) slot = candidate;
        }
        const w3d_u32 delay = slot ? call_virtual(slot->handler.get(), 0x20, arg(now)) : kNoEvent;
        if (delay == 0) {
            index++;
            continue;
        }
        list->begin[index] = list->end[-1];
        list->end.v -= 4;
        if (delay != kNoEvent) {
            EventHeap *heap = group->heap;
            const TimerEvent next = {id, now + delay};
            push_back(static_cast<Vector<TimerEvent> *>(heap), next);
            uint8_t compare = heap->compare;
            A8034a400(heap->begin.get(), heap->end.get(), &compare);
        }
    }
}
}
extern "C" {
void A8034aaf4(void *);
void A8034ab10(void *, w3d_u32, w3d_u32, w3d_u32);
void A8034ad50(void *, w3d_u32, w3d_u32, w3d_u32);
void A80161440(void *);
void A80210afc(void *);
extern w3d_u32 A804b1754;

struct EngineOwner { char pad[0x1c]; Ptr32<EngineState> engine; };
w3d_u32 A8016393c(Ptr32<EngineOwner> self, Ptr32<w3d_u32> time) {
    EngineState *engine = self->engine;
    *time -= engine->base_time;
    const ChangeList *changes = engine->pending;
    PendingChange *change = changes->begin, *const last = changes->end;
    A8034aaf4(engine);
    for (; change != last; change++) {
        const w3d_u32 word = change->target_and_flags;
        const w3d_u32 target = word & ~3u, flags = (word & 3) >> 1;
        if (word & 1) A8034ad50(engine, target, change->value, flags);
        else A8034ab10(engine, target, change->value, flags);
    }
    A80161440(arg(A804b1754));
    A8034af90(Ptr32<TimerGroup>(engine->groups), 3, *time);

    Application *application = at<Application>(A804b178c);
    if (engine->groups[1].heap->end.v == engine->groups[1].heap->begin.v && engine->groups[0].heap->end.v == engine->groups[0].heap->begin.v) {
        engine->idle_since = *time;
        application->idle_since = *time;
    }
    const w3d_u32 frame = (*time + 19) / 20 * 20;
    engine->frame_time = frame;
    application->frame_time = frame;

    at<EngineContext>(A80165254())->in_tick = 2;
    run_finished(&engine->groups[0], frame);
    at<EngineContext>(A80165254())->in_tick = 0;
    at<EngineContext>(A80165254())->in_tick = 2;
    run_finished(&engine->groups[2], frame);
    at<EngineContext>(A80165254())->in_tick = 0;
    A80210afc(engine->frame_end);
    return 0;
}
}
