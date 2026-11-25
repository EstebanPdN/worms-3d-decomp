
// Inferred PPC32 descriptor: next +12, signed priority +20, state +32.
struct Descriptor { unsigned char opaque[12]; Descriptor *next; unsigned char unused[4]; signed char priority; unsigned char gap[11]; int runState; };
extern Descriptor *registry_804b18e8;
extern "C" void w3d_cx9b_registry_sorted_insert_80200a70(Descriptor *entry) {
 Descriptor *scan=registry_804b18e8;
 if(scan) { do { scan=scan->next; } while(scan); }
 Descriptor *head=registry_804b18e8;
 int priority=entry->priority;
 Descriptor *previous=0;
 scan=head;
 while(scan && scan->priority >= priority) { previous=scan; scan=previous->next; }
 if(previous) { entry->next=previous->next; previous->next=entry; }
 else { entry->next=head; registry_804b18e8=entry; }
 entry->runState=0;
}


