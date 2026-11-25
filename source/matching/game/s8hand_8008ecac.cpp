struct s8_Interface { void **vtable; };
struct s8_PairOwner { char pad0[556]; s8_Interface *first,*second; };
extern "C" void s8_clear_pair_8008ecac(s8_PairOwner *self) {
    s8_Interface *zero=0;
    s8_Interface *first=self->first;
    if(first) ((void (*)(s8_Interface *))first->vtable[4])(first);
    self->first=zero;
    s8_Interface *second=self->second;
    if(second) ((void (*)(s8_Interface *))second->vtable[4])(second);
    self->second=zero;
}
