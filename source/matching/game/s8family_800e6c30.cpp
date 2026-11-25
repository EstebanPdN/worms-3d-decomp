struct s8_Triple { int x,y,z; };
struct s8_Base_800dcbc4 {
    s8_Triple source;
    s8_Base_800dcbc4(const s8_Triple *);
};
struct s8_Snapshot_800e6be8 : s8_Base_800dcbc4 {
    char pad12[104];
    s8_Triple snapshot;
    s8_Snapshot_800e6be8();
};
inline void *operator new(unsigned,void *storage) { return storage; }
extern "C" void s8_snapshot_reset_800e6c30(s8_Snapshot_800e6be8 *self,const s8_Triple *from) {
    new ((s8_Base_800dcbc4 *)self) s8_Base_800dcbc4(from);
    self->snapshot=self->source;
}
