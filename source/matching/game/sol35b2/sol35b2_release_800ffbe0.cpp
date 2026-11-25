// Native GC32 task-array cleanup, reconstructed from 800ffbe0.
// Type identities and names are inferred. Only five words of the owner are
// observed. The array uses three native pointer fields and a reference-return
// indexed accessor. Generic range erasure computes byte counts before the
// copy and rereads end afterwards, preserving the observed callback boundary.
// Clearing the entire range naturally produces the original zero-byte copy.
// The original copy site clears CR1 EQ. Its declaration models that observed
// variadic calling boundary; the concrete memcpy body at 802eee50 consumes
// r3/r4/r5 and preserves r3. This is reference ABI evidence, not a portable
// declaration for a replacement standard-library memcpy.
struct Sol35b2Task;
extern "C" void sol35b2_backend_release_801fe288(void *);
extern "C" void sol35b2_task_destroy_800ffb28(Sol35b2Task *,int);
extern "C" void *sol35b2_copy_802eee50(void *,const void *,...);
struct Sol35b2TaskArray {Sol35b2Task **begin,**end,**capacity;
 unsigned size() const {return end-begin;}
 Sol35b2Task *&at(unsigned i) {return begin[i];}
 void erase(Sol35b2Task **first,Sol35b2Task **last) {
  unsigned bytes=(char *)last-(char *)first;
  sol35b2_copy_802eee50(first,last,(unsigned)((char *)end-(char *)last));
  end=(Sol35b2Task **)((char *)end-bytes);
 }
 void clear() {erase(begin,end);}
};
struct Sol35b2TaskOwner {int unknown;Sol35b2TaskArray tasks;void *backend;};
extern "C" void sol35b2_release_800ffbe0(Sol35b2TaskOwner *s) {
 if(s->backend) sol35b2_backend_release_801fe288(s->backend);
 for(unsigned i=0;i<s->tasks.size();++i) {
  Sol35b2Task *task=s->tasks.at(i);
  if(task) sol35b2_task_destroy_800ffb28(task,3);
 }
 s->tasks.clear();
}
