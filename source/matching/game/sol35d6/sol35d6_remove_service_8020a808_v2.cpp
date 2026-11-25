namespace Sol35d6RemoveServiceV2 {
struct Service;
struct Table { void *unused[4]; int (*release)(Service *); };
struct Service { Table *table; };
extern "C" Service **sol35d6_find_8035c414(Service **,Service **,Service *const *);
extern "C" void *sol35d6_copy_802eee50(void *,const void *,unsigned,...);
struct Vector {
    Service **begin, **end, **capacity;
    void erase(Service **position) {
        if (position+1 != end)
            sol35d6_copy_802eee50(position,position+1,
                                (unsigned)end+(-4-(unsigned)position));
        --end;
    }
};
struct Owner { unsigned header[5]; Vector values; Service *held; };
}
extern "C" unsigned sol35d6_remove_service_8020a808_v2(
    Sol35d6RemoveServiceV2::Owner *self,Sol35d6RemoveServiceV2::Service *service) {
    using namespace Sol35d6RemoveServiceV2;
    Vector &values=self->values;
    Service **found=sol35d6_find_8035c414(values.begin,values.end,&service);
    if (found != values.end) {
    values.erase(found);
    service->table->release(service);
    if (self->held == service) {
        if (self->held) self->held->table->release(self->held);
        self->held=0;
    }
    return 0;
    }
    return 0x80004005;
}
