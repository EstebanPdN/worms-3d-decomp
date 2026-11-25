/* GWMP8P rev0 0x80203e04. Object writer by mode: 0 writes the file, 1 records a first-seen object
 * with its type chain counts and streams it, 2 writes the object's index as a varint, else E_FAIL.
 * Real STLport 4.5.3 map keyed by the object pointer. */
#include "compat/stlport_sn_oom.h"
#include <map>
struct D30sTypeChain { char u[20]; D30sTypeChain *next; };
struct D30sWritable { virtual int s0(); virtual int s1(); virtual int s2(); virtual D30sTypeChain *chain(); virtual void *stream(void *); };
typedef std::map<D30sWritable *, int> D30sObjectIds;
typedef D30sObjectIds::_Rep_type D30sObjectIdTree;
template <> _STL::pair<D30sObjectIdTree::iterator, bool> D30sObjectIdTree::insert_unique(const D30sObjectIdTree::value_type &);
struct D30sCountRecord { unsigned id; int count; };
struct D30sObjectWriter { char u0[24]; int mode; char u1[32]; D30sObjectIds ids; };
extern "C" int w3d_d28e_write_file_80204950(D30sObjectWriter *, D30sWritable *);
extern "C" D30sCountRecord *d30s_record_map_get_80205654(D30sObjectWriter *, D30sTypeChain *);
extern "C" int w3d_s21_write_varint_80204760(D30sObjectWriter *, int);
extern "C" int d30s_write_object_80203e04(D30sObjectWriter *self, D30sWritable *obj) {
    D30sObjectIds::iterator i = self->ids.find(obj);
    int hr;
    switch (self->mode) {
    case 0:
        hr = w3d_d28e_write_file_80204950(self, obj);
        return hr;
    case 1:
        if (obj) {
            bool found = i != self->ids.end();
            if (!found) {
                D30sTypeChain *c = obj->chain();
                d30s_record_map_get_80205654(self, c)->count++;
                self->ids.insert(D30sObjectIds::value_type(obj, 0));
                D30sTypeChain *n = c->next; while (n != c && n) { d30s_record_map_get_80205654(self, n); c = n; n = n->next; }
                obj->stream(self);
            }
        }
        return 0;
    case 2:
        hr = w3d_s21_write_varint_80204760(self, obj ? (*i).second : 0);
        return hr;
    case 3:
        hr = 0;
        break;
    }
    hr = 0x80004005;
    return hr;
}
