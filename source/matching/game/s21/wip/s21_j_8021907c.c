struct S21Handle { char pad[24]; int handle; };
extern int fn_802e4cfc(int);
int w3d_s21_check_handle_8021907c(struct S21Handle *self,int unused,int expected,int *actual){int value=fn_802e4cfc(self->handle); if(actual) *actual=value; if(value!=expected) return 0x80004005; return 0; }
