// Observed vector footprints and two tree headers. Semantic labels inferred.
namespace Sol35d6ClearTablesV5 {
struct Record { unsigned words[16]; };
struct Value { unsigned word; };
template<class T> inline void destroy_one(T *p) { p->~T(); }
template<class T> inline void destroy_aux(T *first,T *last) {
    for(;first!=last;++first) destroy_one(first);
}
template<class T> inline void destroy_range(T *first,T *last) {
    destroy_aux(first,last);
}
template<class T> struct Vector {
    T *begin,*end; unsigned allocator; T *capacity;
    void erase_at_end(T *first) { destroy_range(first,end); end=first; }
    void clear() { erase_at_end(begin); }
};
struct Node { unsigned color; Node *parent,*left,*right; };
struct FirstTree;
struct SecondTree;
extern "C" void sol35d6_erase_first_8035b84c(FirstTree *,Node *);
extern "C" void sol35d6_erase_second_8035b8a4(SecondTree *,Node *);
struct FirstTree {
    unsigned allocator; Node *header; unsigned count,comparison;
    void clear() {
        if(count) {
            sol35d6_erase_first_8035b84c(this,header->parent);
            header->left=header;
            header->parent=0;
            header->right=header;
            count=0;
        }
    }
};
struct SecondTree {
    unsigned allocator; Node *header; unsigned count,comparison;
    void clear() {
        if(count) {
            sol35d6_erase_second_8035b8a4(this,header->parent);
            header->left=header;
            header->parent=0;
            header->right=header;
            count=0;
        }
    }
};
struct Owner {
    unsigned prefix[6],state;
    Vector<Record> records;
    FirstTree first;
    SecondTree second;
    unsigned unknown76[4];
    Vector<Value> values;
};
}
extern "C" void sol35d6_clear_tables_80204850_v5(Sol35d6ClearTablesV5::Owner *self) {
    Sol35d6ClearTablesV5::Record *start=self->records.begin;
    Sol35d6ClearTablesV5::FirstTree &first=self->first;
    Sol35d6ClearTablesV5::SecondTree &second=self->second;
    Sol35d6ClearTablesV5::Vector<Sol35d6ClearTablesV5::Value> &values=self->values;
    self->records.erase_at_end(start);
    first.clear();
    second.clear();
    Sol35d6ClearTablesV5::Value *valueStart=self->values.begin;
    self->state=0;
    values.erase_at_end(valueStart);
}
typedef char Sol35d6ClearRecordsOffset[(unsigned)&((Sol35d6ClearTablesV5::Owner*)0)->records==28?1:-1];
typedef char Sol35d6ClearValuesOffset[(unsigned)&((Sol35d6ClearTablesV5::Owner*)0)->values==92?1:-1];
