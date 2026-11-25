#include "w3d_ptr.h"
#line 1 "cc38b_prune_elements_802bc600.cpp"
// Partial text-element vector. Original copy call uses the variadic-call ABI.
struct Cc38bElement{unsigned unknown[4];int keep;};
extern "C" void cc38b_destroy_802bcfb4(Ptr32<Cc38bElement>,int);
extern "C" Ptr32<void> cc38b_copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned,...);
struct Cc38bElements{Ptr32<Ptr32<Cc38bElement>> begin; Ptr32<Ptr32<Cc38bElement>> end;
 Ptr32<Ptr32<Cc38bElement>> finish(){return end;}
 void erase(Ptr32<Ptr32<Cc38bElement>> p){
 if(p+1!=end)cc38b_copy_802eee50(p,p+1,(Ptr32<char>)end-((Ptr32<char>)p+4));
 --end;
 }
};
struct Cc38bList{char unknown[56];Cc38bElements elements;};
extern "C" void cc38b_prune_elements_802bc600(Ptr32<Cc38bList> self){
 Ptr32<Ptr32<Cc38bElement>> p=self->elements.begin;
 if(p!=self->elements.finish()){do{
 Ptr32<Cc38bElement> element=*p;
 if(!element->keep){
 if(element)cc38b_destroy_802bcfb4(element,3);
 self->elements.erase(p);
 }else ++p;
 }while(p!=self->elements.finish());}
}


