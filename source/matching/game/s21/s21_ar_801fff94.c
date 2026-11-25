// desc: Appears to report whether bits 3 to 5 of a halfword in the looked-up object equal two.
struct S21Info { char pad[4]; unsigned short bits; };
extern struct S21Info *fn_802001a8(void *);
int w3d_s21_kind_is_two_801fff94(void *self)
{
    return ((fn_802001a8(self)->bits >> 3) & 7) == 2;
}
