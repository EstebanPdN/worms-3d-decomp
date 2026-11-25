// Names, roles, types, qualifiers and layouts are inferred from original instructions.
struct F11c_Interface336{void**table;};struct F11c_Held336{F11c_Interface336*p;F11c_Held336():p(0){}void assign(F11c_Interface336*q){if(q)((void(*)(F11c_Interface336*))q->table[3])(q);if(p)((void(*)(F11c_Interface336*))p->table[4])(p);p=q;}~F11c_Held336(){if(p)((void(*)(F11c_Interface336*))p->table[4])(p);}};
struct F11c_Key336{unsigned value;F11c_Held336 held;};
struct F11c_Node336{unsigned color;F11c_Node336*parent,*left,*right;unsigned key;F11c_Interface336*held;};
inline bool less336(unsigned a,F11c_Interface336*b,unsigned c,F11c_Interface336*d){bool result=false;if(a<c||(a==c&&b<d))result=true;return result;}
struct F11c_Iterator336{F11c_Node336*p;F11c_Iterator336(F11c_Node336*q):p(q){}F11c_Iterator336(const F11c_Iterator336&o):p(o.p){}F11c_Iterator336&operator=(const F11c_Iterator336&o){p=o.p;return *this;}};
struct F11c_Tree336{unsigned unknown;F11c_Node336*header;F11c_Iterator336 find(const F11c_Key336&key){F11c_Node336*candidate=header;F11c_Node336*node=header->parent;while(node){bool less=false;if(node->key<key.value||(node->key==key.value&&node->held<key.held.p))less=true;if(!less){candidate=node;node=node->left;}else node=node->right;}if(candidate!=header){bool less=false;if(key.value<candidate->key||(key.value==candidate->key&&key.held.p<candidate->held))less=true;if(!less)goto found;}candidate=header;found:return F11c_Iterator336(candidate);}};
extern "C" F11c_Iterator336*f11c_tree_find_801d295c(F11c_Iterator336*out,void*unused,F11c_Interface336*held,unsigned value,F11c_Tree336*tree){F11c_Key336 key;key.held.assign(held);key.value=value;F11c_Iterator336 it=tree->find(key);*out=it;return out;}

