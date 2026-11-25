/* AI command builders that take a float amount (0x800085fc, 0x8000889c,
 * 0x80009014). Each allocates a command through 0x8001523c, fills it, appends
 * its base pointer to the global command storage (0x804aa564) and hands it to
 * the registry at 0x804aa5a4 (0x8002274c). Two commands are built by
 * out-of-line constructors (0x80021514, 0x80021768); the third is the type-16
 * command with table 0x8040dbc8, an int value and a float amount. Layouts
 * follow the observed offsets; names are inferred. Built with -mps-float
 * (frame keeps 8 bytes below the save area for the saved FPR). */
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
extern "C" unsigned char *d17a_allocate_80212fd4(unsigned);
extern "C" void d17a_release_802134fc(void *);
extern "C" void *d17a_copy_802eee50(void *, const void *, ...);
inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &smaller(const unsigned &a, const unsigned &b) { return b < a ? b : a; }

struct D17aCommand;
struct D17aCommandStorage {
    unsigned char *begin, *end, *capacity;
    void push(D17aCommand *const &value)
    {
        if (end == capacity) {
            unsigned used = end - begin;
            int next = used + 1;
            int grown = used + (used >> 1);
            unsigned allocated = larger(next, grown) * 4;
            unsigned char *fresh = d17a_allocate_80212fd4(allocated);
            if (begin) {
                d17a_copy_802eee50(fresh, begin, smaller(allocated, used));
                d17a_release_802134fc(begin);
            }
            begin = fresh;
            end = fresh + used;
            capacity = fresh + allocated;
        }
        new (end) D17aCommand *(value);
        end += 4;
    }
};

struct D17aCommand { unsigned unknown00, link4, link8, type; void *table; };

/* Command whose fields are set by the out-of-line constructor 0x80021514. */
struct D17aCommand_80021514 : D17aCommand {
    D17aCommand_80021514();
    unsigned char unknown14[8];
    float amount;
};

/* Command whose fields are set by the out-of-line constructor 0x80021768. */
struct D17aCommand_80021768 : D17aCommand {
    D17aCommand_80021768();
    unsigned char unknown14[4];
    float amount;
};

extern char d17a_command_table_16_8040dbc8[];
struct D17aValueCommand : D17aCommand {
    int value;
    float amount;
    void initialize() { link4 = 0; link8 = 0; table = d17a_command_table_16_8040dbc8; type = 16; }
};

extern D17aCommandStorage *d17a_commands_804aa564;
extern void *d17a_registry_804aa5a4;
extern "C" void *d17a_allocate_8001523c(unsigned);
extern "C" void d17a_register_8002274c(void *, D17aCommand *);

extern "C" void w3d_d17a_command_create_800085fc(float amount)
{
    D17aCommand_80021514 *command =
        new (d17a_allocate_8001523c(sizeof(D17aCommand_80021514))) D17aCommand_80021514;
    d17a_commands_804aa564->push(static_cast<D17aCommand *>(command));
    command->amount = amount;
    d17a_register_8002274c(d17a_registry_804aa5a4, command);
}

extern "C" void w3d_d17a_command_create_8000889c(float amount)
{
    D17aCommand_80021768 *command =
        new (d17a_allocate_8001523c(sizeof(D17aCommand_80021768))) D17aCommand_80021768;
    d17a_commands_804aa564->push(static_cast<D17aCommand *>(command));
    command->amount = amount;
    d17a_register_8002274c(d17a_registry_804aa5a4, command);
}

extern "C" void w3d_d17a_command_create_16_80009014(int value, float amount)
{
    D17aValueCommand *command =
        new (d17a_allocate_8001523c(sizeof(D17aValueCommand))) D17aValueCommand;
    command->initialize();
    command->value = value;
    command->amount = amount;
    d17a_commands_804aa564->push(static_cast<D17aCommand *>(command));
    d17a_register_8002274c(d17a_registry_804aa5a4, command);
}

typedef char d17a_command_32[sizeof(D17aCommand_80021514) == 32 ? 1 : -1];
typedef char d17a_command_28[sizeof(D17aCommand_80021768) == 28 ? 1 : -1];
typedef char d17a_value_command[sizeof(D17aValueCommand) == 28 ? 1 : -1];
