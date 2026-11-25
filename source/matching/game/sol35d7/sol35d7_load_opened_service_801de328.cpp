// Partial native vtables: only called slots have inferred signatures.
namespace sol35d7_load_opened_service {
struct Opened;
struct OpenedTable {
 void (*unknown[3])();
 void (*retain)(Opened *);
 void (*release)(Opened *);
};
struct Opened {OpenedTable *table;};
struct Provider;
struct ProviderTable {
 void (*unknown[5])();
 int (*open)(Provider *,const char *,int,Opened **);
};
struct Provider {ProviderTable *table;};
struct Loader;
struct LoaderTable {
 void (*unknown[3])();
 void (*retain)(Loader *);
 void (*release)(Loader *);
 void (*bind)(Loader *,Opened *);
 void (*unknown_18[2])();
 int (*load)(Loader *,void *,int);
};
struct Loader {LoaderTable *table;};
template<class T>struct Held {
 T *ptr;
 Held():ptr(0) {}
 explicit Held(T *p):ptr(p) {if(ptr)ptr->table->retain(ptr);}
 ~Held(){if(ptr)ptr->table->release(ptr);}
 T *operator->() const {return ptr;}
};
extern "C" Provider *fn_8020b884();
extern "C" Loader *fn_8020b680(const void *);
extern unsigned char lbl_80418f78[];
typedef char HeldSize[(sizeof(Held<Opened>)==4 && sizeof(Held<Loader>)==4)?1:-1];
}
extern "C" int sol35d7_load_opened_service_801de328(void *destination,const char *name,sol35d7_load_opened_service::Provider *provider) {
 using namespace sol35d7_load_opened_service;
 Held<Opened> opened;
 if(!provider)provider=fn_8020b884();
 int result=provider->table->open(provider,name,2,&opened.ptr);
 if(result>=0) {
  Held<Loader> loader(fn_8020b680(lbl_80418f78));
  loader->table->bind(loader.ptr,opened.ptr);
  result=loader->table->load(loader.ptr,destination,0);
 }
 return result;
}
