struct S21Cycler { char pad[332]; int index; };
extern void fn_802c38cc(struct S21Cycler *, int);
void w3d_s21_cycle_index_802c4080(struct S21Cycler *self){ int c = self->index; int next; if (c == 5) next = 0; else next = c+1; fn_802c38cc(self,next);}