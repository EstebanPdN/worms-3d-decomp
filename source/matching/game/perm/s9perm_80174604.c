/* Ready flag observed at byte offset 24. */
typedef struct S9ReadyState { char unknown[24]; unsigned int flags; } S9ReadyState;
int s9_permute_80174604(const S9ReadyState *self)
{
    if(!(self->flags & 0x8000))return 0x80004005;
    return 0;
}
