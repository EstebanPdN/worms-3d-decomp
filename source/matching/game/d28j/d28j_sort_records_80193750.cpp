// Sort the records and their element lists by name, GWMP8P rev0 0x80193750.
// Builds an index vector, bubble sorts it by record name, copies records and
// lists in sorted order into temporary vectors, clears and shrinks the
// object's vectors, resizes them and copies back. Vectors are STLport-shaped.
// The default element is a temporary inside the inline one-argument resize
// overload, as in STLport, which gives the shared stack block and the address
// registers; the record body's destructor and the string's constructor are out
// of line. An empty allocator class with user constructor and copy constructor
// is passed as the vector constructor's default argument; it is not witnessed
// by a read or write (see caveats in the worker report).

extern "C" void fn_8020c5c4(void *);
extern "C" void fn_80341588(void *);
extern "C" void fn_8020bb2c(void *);
extern "C" void fn_801907d0(void *);
extern "C" void fn_802134fc(void *);
extern "C" int strcmp_802ef234(const char *, const char *);
struct Hdr { unsigned short refs; };
struct Str {
    char *text;
    void *self() { return this; }
    Str(const Str &);
    Str();
    ~Str() { fn_8020c5c4(self()); fn_80341588(self()); }
    Str &operator=(const Str &o) {
        ((Hdr *)(o.text - 6))->refs++;
        Hdr *h = (Hdr *)(text - 6);
        if (--h->refs == 0) fn_8020bb2c(h);
        text = o.text;
        return *this;
    }
};
struct Body {
    char b[72];
    Body();
    ~Body();
};
struct Record {
    Str name; float weight; Body body; unsigned char flag;
    Record &operator=(const Record &o) { name = o.name; weight = o.weight; body = o.body; flag = o.flag; return *this; }
};
struct Elem { int word; int inner[2]; ~Elem() {} };
struct VAl { VAl() {} VAl(const VAl &) {} };
template<class T> inline void v_dist(T *first, T *last, int &n) { n += last - first; }
template<class T> inline T *v_copy(T *first, T *last, T *out) {
    int n = 0;
    v_dist(first, last, n);
    for (; n > 0; --n) { *out = *first; ++first; ++out; }
    return out;
}
template<class T> struct VEnd { int a; T *data; VEnd(const VAl &, T *p) { data = p; } };
struct IntVec {
    int *start, *finish;
    VEnd<int> end;
    IntVec(const VAl &a = VAl()) : start(0), finish(0), end(a, 0) {}
    ~IntVec() { if (start) fn_802134fc(start); }
    unsigned size() const { return finish - start; }
    int &operator[](unsigned i) { return start[i]; }
    void erase(int *first, int *last) { finish = first; }
    void resize(unsigned n, const int &x = 0);
};
extern "C" void insert_80344380(IntVec *, int *, unsigned, const int *);
inline void IntVec::resize(unsigned n, const int &x) {
    if (n < size()) erase(start + n, finish);
    else insert_80344380(this, finish, n - size(), &x);
}
struct RecVec {
    Record *start, *finish;
    VEnd<Record> end;
    RecVec(const VAl &a = VAl()) : start(0), finish(0), end(a, 0) {}
    ~RecVec() {
        Record *l = finish;
        for (Record *p = start; p != l; ++p) p->~Record();
        if (start) fn_801907d0(start);
    }
    unsigned size() const { return finish - start; }
    Record &operator[](unsigned i) { return start[i]; }
    void erase(Record *first, Record *last) {
        Record *e = v_copy(last, finish, first);
        Record *l = finish;
        for (Record *p = e; p != l; ++p) p->~Record();
        finish = e;
    }
    void clear() { erase(start, finish); }
    void resize(unsigned n, const Record &x);
    void resize(unsigned n);
};
extern "C" void insert_8034db14(RecVec *, Record *, unsigned, const Record *);
inline void RecVec::resize(unsigned n, const Record &x) {
    if (n < size()) erase(start + n, finish);
    else insert_8034db14(this, finish, n - size(), &x);
}
struct ElemVec;
extern "C" int assign_8034e408(ElemVec *, const ElemVec *);
struct ElemBase {
    Elem *start, *finish;
    VEnd<Elem> end;
    ElemBase(const VAl &a) : start(0), finish(0), end(a, 0) {}
    ~ElemBase() { if (start) fn_801907d0(start); }
};
struct ElemVec : ElemBase {
    ElemVec(const VAl &a = VAl()) : ElemBase(a) {}
    ElemVec &operator=(const ElemVec &o) { assign_8034e408(this, &o); return *this; }
    ~ElemVec() {
        Elem *l = finish;
        for (Elem *p = start; p != l; ++p) p->~Elem();
    }
};
struct ListVec {
    ElemVec *start, *finish;
    VEnd<ElemVec> end;
    ListVec(const VAl &a = VAl()) : start(0), finish(0), end(a, 0) {}
    ~ListVec() {
        ElemVec *l = finish;
        for (ElemVec *p = start; p != l; ++p) p->~ElemVec();
        if (start) fn_801907d0(start);
    }
    unsigned size() const { return finish - start; }
    ElemVec &operator[](unsigned i) { return start[i]; }
    void erase(ElemVec *first, ElemVec *last) {
        ElemVec *e = v_copy(last, finish, first);
        ElemVec *l = finish;
        for (ElemVec *p = e; p != l; ++p) p->~ElemVec();
        finish = e;
    }
    void clear() { erase(start, finish); }
    void resize(unsigned n, const ElemVec &x);
    void resize(unsigned n);
};
extern "C" void insert_8034e638(ListVec *, ElemVec *, unsigned, const ElemVec *);
inline void ListVec::resize(unsigned n, const ElemVec &x) {
    if (n < size()) erase(start + n, finish);
    else insert_8034e638(this, finish, n - size(), &x);
}
inline void RecVec::resize(unsigned n) { resize(n, Record()); }
inline void ListVec::resize(unsigned n) { resize(n, ElemVec()); }
extern "C" void reserve_8034ee28(RecVec *, unsigned);
extern "C" void reserve_8034efd0(ListVec *, unsigned);
struct Self { char u0[36]; RecVec records; ListVec lists; char u44[4]; unsigned listCount; };
extern "C" void d28j_sort_records_80193750(Self *self) {
    unsigned c = self->listCount;
    if (c == 0) return;
    IntVec order;
    order.resize(c);
    unsigned i;
    for (i = 0; i < self->listCount; ++i) order[i] = i;
    for (unsigned last = self->listCount - 1; last != 0; --last) {
        for (unsigned j = 0; j < last; ++j) {
            if (strcmp_802ef234(self->records[order[j + 1]].name.text, self->records[order[j]].name.text) < 0) {
                int t = order[j];
                order[j] = order[j + 1];
                order[j + 1] = t;
            }
        }
    }
    RecVec sorted;
    ListVec lists2;
    sorted.resize(self->listCount);
    lists2.resize(self->listCount);
    for (i = 0; i < self->listCount; ++i) {
        sorted[i] = self->records[order[i]];
        lists2[i] = self->lists[order[i]];
    }
    self->records.clear();
    self->lists.clear();
    reserve_8034ee28(&self->records, 0);
    reserve_8034efd0(&self->lists, 0);
    self->records.resize(self->listCount);
    self->lists.resize(self->listCount);
    for (i = 0; i < self->listCount; ++i) {
        self->records[i] = sorted[i];
        self->lists[i] = lists2[i];
    }
}
