struct s8_Triple { int x,y,z; };
struct s8_Base_800dca2c {
    s8_Triple source;
    s8_Base_800dca2c(int,int);
};
struct s8_Snapshot_800e6be8 : s8_Base_800dca2c {
    char pad12[104];
    s8_Triple snapshot;
    s8_Snapshot_800e6be8();
};
inline void *operator new(unsigned,void *storage) { return storage; }
extern "C" void s8_snapshot_reset_800e6be8(s8_Snapshot_800e6be8 *self,int a,int b) {
    new ((s8_Base_800dca2c *)self) s8_Base_800dca2c(a,b);
    self->snapshot=self->source;
}
