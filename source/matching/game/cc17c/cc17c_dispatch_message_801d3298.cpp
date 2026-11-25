/* Observed message: 16-bit handler index at +6. */
struct Cc17cMessage { char pad0[6]; unsigned short index; };
struct Cc17cDispatchPart;
typedef int (*Cc17cHandler)(Cc17cDispatchPart *, Cc17cMessage *);
/* Observed: the part at dispatcher +4 holds a state word at its +16 and the handler table at its +24. */
struct Cc17cDispatchPart { char pad0[16]; int state; char pad20[4]; Cc17cHandler *handlers; };
struct Cc17cHandlerSource;
struct Cc17cHandlerSourceTable { char pad0[40]; Cc17cHandler *(*handlers)(Cc17cHandlerSource *); };
struct Cc17cHandlerSource { Cc17cHandlerSourceTable *vtable; };
struct Cc17cDispatcher;
/* Observed virtual slots (4-byte entries) +20, +28, +32, +44; inferred roles. */
struct Cc17cDispatcherTable {
    char pad0[20];
    int (*query_state)(Cc17cDispatcher *);
    char pad24[4];
    int (*begin)(Cc17cDispatcher *, Cc17cMessage *);
    int (*end)(Cc17cDispatcher *, Cc17cMessage *);
    char pad36[8];
    Cc17cHandlerSource *(*handler_source)(Cc17cDispatcher *);
};
struct Cc17cDispatcher { Cc17cDispatcherTable *vtable; Cc17cDispatchPart part; };
extern "C" int w3d_cc17c_dispatch_message_801d3298(Cc17cDispatcher *self, Cc17cMessage *message)
{
    self->part.state = self->vtable->query_state(self);
    Cc17cHandlerSource *source = self->vtable->handler_source(self);
    self->part.handlers = source->vtable->handlers(source);
    int result = self->vtable->begin(self, message);
    if (result >= 0) {
        Cc17cDispatchPart *part = &self->part;
        result = part->handlers[message->index](part, message);
        self->vtable->end(self, message);
    }
    if (result == (int)0x90000005) return 0;
    if (result >= 0) return 0x80004005;
    return result;
}
