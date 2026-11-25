/* Observed singleton service pointer +100, virtual slot +128 and one-word
   stack copy of the incoming name handle. */
struct Cc17bForwardService { int (**vtable)(); };
struct Cc17bForwardRoot { char pad[100]; Cc17bForwardService *service; };
extern "C" {
extern Cc17bForwardRoot *root_804b1788;
int w3d_cc17b_service_forward_800fd62c(const unsigned *name,unsigned a,unsigned b,unsigned c) {
 unsigned local=*name;
 Cc17bForwardService *service=root_804b1788->service;
 return ((int (*)(Cc17bForwardService *,unsigned *,unsigned,unsigned,unsigned))service->vtable[32])(service,&local,a,b,c);
}
}
