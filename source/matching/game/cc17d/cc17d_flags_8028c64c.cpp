struct Cc17dFlagTarget { char pad00[16]; int enabled; };
struct Cc17dFlagOwner {
    char pad000[176];
    bool item;                        /* +176 */
    char pad0b4[252 - 180];
    Cc17dFlagTarget *a;               /* +252 */
    Cc17dFlagTarget *b;               /* +256 */
    char pad104[272 - 260];
    Cc17dFlagTarget *c;               /* +272 */
    char pad114[312 - 276];
    bool mode;                        /* +312 */
};
extern "C" void w3d_cc17d_update_flags_8028c64c(Cc17dFlagOwner *self)
{
    bool other = !self->mode & self->item;
    bool both = self->mode & self->item;
    self->a->enabled = self->b->enabled = other;
    self->c->enabled = both;
}
