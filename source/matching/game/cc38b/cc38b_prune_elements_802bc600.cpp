// Partial text-element vector. Original copy call uses the variadic-call ABI.
struct Cc38bElement{unsigned unknown[4];int keep;};
extern "C" void cc38b_destroy_802bcfb4(Cc38bElement*,int);
extern "C" void*cc38b_copy_802eee50(void*,const void*,unsigned,...);
struct Cc38bElements{Cc38bElement**begin,**end;
 Cc38bElement** finish(){return end;}
 void erase(Cc38bElement**p){
 if(p+1!=end)cc38b_copy_802eee50(p,p+1,(char*)end-((char*)p+4));
 --end;
 }
};
struct Cc38bList{char unknown[56];Cc38bElements elements;};
extern "C" void cc38b_prune_elements_802bc600(Cc38bList*self){
 Cc38bElement**p=self->elements.begin;
 if(p!=self->elements.finish()){do{
 Cc38bElement*element=*p;
 if(!element->keep){
 if(element)cc38b_destroy_802bcfb4(element,3);
 self->elements.erase(p);
 }else ++p;
 }while(p!=self->elements.finish());}
}
