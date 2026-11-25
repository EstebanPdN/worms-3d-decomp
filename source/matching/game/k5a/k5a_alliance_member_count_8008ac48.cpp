struct K5aHandle { int object; unsigned int tag; };
struct K5aTeam { unsigned char pad0[60]; unsigned char alliance; };
struct K5aTeamStats { unsigned char pad0[20]; int member_count; };
extern "C" K5aTeam *s8_handle_800fc82c(unsigned int index, K5aHandle *handle);
extern "C" K5aTeamStats *s8_handle_800fc948(unsigned int index, K5aHandle *handle);
extern "C" void w3d_s20_destroy_owned_80178474(K5aHandle *handle, int flags);

extern "C" void k5a_alliance_member_count_8008ac48(void *self, int alliance)
{
    struct { K5aHandle handle; char spare[0]; } local;
    unsigned int i;
    local.handle.object = 0;
    local.handle.tag = 0xe3a8;
    i = 0;
    do
    {
        if (s8_handle_800fc82c(i, &local.handle)->alliance == alliance)
            s8_handle_800fc948(i, &local.handle)->member_count++;
        i++;
    } while (i <= 3);
    w3d_s20_destroy_owned_80178474(&local.handle, 2);
}
