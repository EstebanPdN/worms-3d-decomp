// Partial PPC32 node and service views; list and object roles are inferred.
struct Node {Node *next; char unknown[36]; char *object;};
struct Iterator {Node *node; Iterator(Node*n):node(n){}Iterator(const Iterator&o){node=o.node;} int operator!=(const Iterator&o)const{if(node==o.node)return 0;return 1;} Node *operator->()const{return node;}};
struct List {int unknown;Node *sentinel;Iterator begin(){return Iterator(sentinel->next);}Iterator end(){return Iterator(sentinel);}};
struct Service {void **table;};
struct Owner {char unknown[20];Service *service;List list;};
inline char *adjust(char*p){return p?p+4:0;}
extern "C" int f1b_drain_list_service_8016636c(Owner*s){while(s->list.begin()!=s->list.end()){((void(*)(Service*,char*,int))s->service->table[12])(s->service,adjust(s->list.begin()->object),0);}return 0;}
