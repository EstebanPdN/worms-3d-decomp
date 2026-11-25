/* String operations and record offsets inferred from original instructions. */
typedef struct { char *text; unsigned int opaque; } String;
typedef struct { char pad[4]; char *name; } Record;
extern Record ***lbl_804aa750;
extern char lbl_8036a7e4[];
extern void fn_8000756c(void *, String *), fn_8020bb54(String *, char *), fn_8020c5c0(String *), fn_8020c5c4(String *), fn_80341588(String *), fn_8020bf2c(String *, char *);
extern unsigned short *fn_80341884(String *);
void tterra_z37_name_800178b4(char *self, String *out) {
 String slots[3]; Record *entry;
 fn_8000756c(self,out);
 fn_8020bb54(&slots[1],lbl_8036a7e4);
 entry=*(Record **)((char *)*lbl_804aa750 + (*(int *)(self+44) << 2));
 fn_8020c5c0(&slots[2]); slots[2].text=slots[1].text; ++*fn_80341884(&slots[2]);
 fn_8020bf2c(&slots[2],entry->name);
 fn_8020c5c0(&slots[0]); slots[0].text=slots[2].text; ++*fn_80341884(&slots[0]);
 fn_8020c5c4(&slots[2]); fn_80341588(&slots[2]);
 fn_8020bf2c(out,slots[0].text);
 fn_8020c5c4(&slots[0]); fn_80341588(&slots[0]);
 fn_8020c5c4(&slots[1]); fn_80341588(&slots[1]);
}
