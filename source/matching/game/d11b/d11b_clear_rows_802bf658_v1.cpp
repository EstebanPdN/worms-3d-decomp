// Observed row stride is 24 bytes. Only the vector's begin/end prefix and the
// owner's prefix are known; no complete container/owner sizeof is asserted.
struct d11b_RowResource;
struct d11b_RowResourceTable { unsigned int unknown00[3]; void (*retain)(d11b_RowResource *); void (*release)(d11b_RowResource *); };
struct d11b_RowResource { d11b_RowResourceTable *vtable; };
struct d11b_RowHandle {
    d11b_RowResource *value;
    void reset(d11b_RowResource *next) { if(value)value->vtable->release(value);value=next; }
    d11b_RowHandle &operator=(const d11b_RowHandle &other) {
        if(other.value)other.value->vtable->retain(other.value);
        if(value)value->vtable->release(value);
        value=other.value; return *this;
    }
    ~d11b_RowHandle() { if(value)value->vtable->release(value); }
};
struct d11b_Row {
    d11b_RowHandle handle; float x,y; unsigned int state; float width,height;
    d11b_Row &operator=(const d11b_Row &other) {
        handle=other.handle;x=other.x;y=other.y;state=other.state;width=other.width;height=other.height;return *this;
    }
};
static inline d11b_Row *d11b_copy_rows(d11b_Row *first,d11b_Row *last,d11b_Row *result) {
    for(int count=last-first;count>0;--count) { *result=*first; ++first; ++result; }
    return result;
}
struct d11b_RowVector {
    d11b_Row *begin,*end;
    void erase(d11b_Row *position) {
        d11b_Row *next=position+1;
        if(next!=end) {
            d11b_copy_rows(next,end,position);
        }
        --end;
        end->~d11b_Row();
    }
};
struct d11b_RowOwner { unsigned char unknown00[80]; d11b_RowVector rows; };
extern "C" void d11b_clear_rows_802bf658(d11b_RowOwner *self) {
    d11b_Row *position=self->rows.begin;
    while(position!=self->rows.end) {
        position->handle.reset(0);
        self->rows.erase(position);
    }
}
