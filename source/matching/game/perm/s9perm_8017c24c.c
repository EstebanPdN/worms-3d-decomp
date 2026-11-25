/* State field observed at byte offset 20. */
typedef struct S9Status { char unknown[20]; int value; } S9Status;
int s9_permute_8017c24c(const S9Status *self)
{
    if (self->value >= 0) return 0x80004005;
    return 0x80004001;
}
