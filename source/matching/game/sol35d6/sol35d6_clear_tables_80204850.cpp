// Observed vector footprints and two tree headers. Semantic labels inferred.
namespace Sol35d6ClearTables {
struct Record { unsigned words[16]; };
struct Value { unsigned word; };
template<class T> inline void destroy_range(T *first,T *last) {
    for(;first!=last;++first) first->~T();
}
template<class T> struct Vector {
    T *begin,*end; unsigned allocator; T *capacity;
    void clear() { destroy_range(begin,end); end=begin; }
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
extern "C" void sol35d6_clear_tables_80204850(Sol35d6ClearTables::Owner *self) {
    self->records.clear();
    self->first.clear();
    self->second.clear();
    self->state=0;
    self->values.clear();
}
typedef char Sol35d6ClearRecordsOffset[(unsigned)&((Sol35d6ClearTables::Owner*)0)->records==28?1:-1];
typedef char Sol35d6ClearValuesOffset[(unsigned)&((Sol35d6ClearTables::Owner*)0)->values==92?1:-1];
