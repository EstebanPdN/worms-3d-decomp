// GWMP8P rev0 0x8019e96c. Fills a locked stream from the Lua table on the
// stack: for each row accepts a number, a table of named element values, or
// failing any name a table of positional values, converting each through the
// service's converter into the row at the element's offset. Names inferred.
struct lua_State;
extern "C" int w3d_k6b_lua_table_length_802cd408(lua_State *, int);
extern "C" void lua_pushnumber(lua_State *, float);
extern "C" void lua_gettable(lua_State *, int);
extern "C" int lua_isnumber(lua_State *, int);
extern "C" float lua_tonumber(lua_State *, int);
extern "C" int lua_type(lua_State *, int);
extern "C" void lua_settop(lua_State *, int);
extern "C" void lua_pushstring(lua_State *, const char *);
struct Element;
extern "C" const char *fn_801ffea8(Element *);
extern "C" int fn_80200134(Element *);
struct Layout {
    virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24();
    virtual Element **Elements(unsigned *count);
};
extern "C" int fn_80200050(Layout *);
extern "C" Layout *fn_80200158(Element *);
extern char type_float_8045ed7c[];
extern char convert_key_80419500[];
struct Converter {
    virtual void s8(); virtual void retain(); virtual void release(); virtual void s20();
    virtual void Convert(void *value, void *type, void *dst, struct Layout *layout);
};
struct ConverterRef {
    Converter *p;
    ConverterRef(Converter *q) : p(q) { if (p) p->retain(); }
    ConverterRef(const ConverterRef &o) : p(o.p) { if (p) p->retain(); }
    ~ConverterRef() { if (p) p->release(); }
};
struct Service {
    virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36();
    virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void s56(); virtual void s60(); virtual void s64(); virtual void s68();
    virtual void s72(); virtual void s76(); virtual void s80(); virtual void s84(); virtual void s88();
    virtual Converter *Find(void *key);
};
extern "C" Service *fn_8020b648();
struct Format { char u0[8]; Layout *layout; };
struct Stream { Format *format; virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32();
    virtual char *Lock(int usage, int count, int a, int b); };
inline Converter *FindConverter(void *key) { return fn_8020b648()->Find(key); }
extern "C" int w3d_d40n_lua_fill_vertex_stream_8019e96c(lua_State *L, int usage, Stream *stream) {
    int count = w3d_k6b_lua_table_length_802cd408(L, -1);
    ConverterRef conv(FindConverter(convert_key_80419500));
    char *dst = stream->Lock(usage, count, 1, 0);
    Layout *layout = stream->format->layout;
    int stride = fn_80200050(layout);
    for (int i = 1; i <= count; i++) {
        lua_pushnumber(L, (float)i);
        lua_gettable(L, -2);
        if (lua_isnumber(L, -1)) {
            float v = lua_tonumber(L, -1);
            conv.p->Convert(&v, type_float_8045ed7c, dst, layout);
        } else if (lua_type(L, -1) == 5) {
            unsigned n;
            Element **elems = layout->Elements(&n);
            if (elems) {
                int named = 0;
                for (unsigned j = 0; j < n; j++) {
                    Element *e = elems[j];
                    lua_pushstring(L, fn_801ffea8(e));
                    lua_gettable(L, -2);
                    if (lua_type(L, -1) != 0) {
                        named = 1;
                        if (lua_isnumber(L, -1)) {
                            float v = lua_tonumber(L, -1);
                            conv.p->Convert(&v, type_float_8045ed7c, dst + fn_80200134(e), fn_80200158(e));
                        }
                    }
                    lua_settop(L, -2);
                }
                if (!named) {
                    unsigned len = w3d_k6b_lua_table_length_802cd408(L, -1);
                    for (unsigned j = 0; j < n && j < len; j++) {
                        Element *e = elems[j];
                        lua_pushnumber(L, (float)j + 1.0f);
                        lua_gettable(L, -2);
                        if (lua_type(L, -1) != 0 && lua_isnumber(L, -1)) {
                            float v = lua_tonumber(L, -1);
                            conv.p->Convert(&v, type_float_8045ed7c, dst + fn_80200134(e), fn_80200158(e));
                        }
                        lua_settop(L, -2);
                    }
                }
            }
        }
        lua_settop(L, -2);
        dst += stride;
    }
    return 0;
}
