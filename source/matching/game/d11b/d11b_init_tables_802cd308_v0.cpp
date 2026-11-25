// Observed static table constructor: four sixteen-element pointer tables and
// sixteen sixteen-byte records. Record offset eight is intentionally untouched.
inline void *operator new[](unsigned int,void *place) { return place; }
struct d11b_TablePointer { void *value; d11b_TablePointer():value(0) {} };
struct d11b_TableTail { unsigned int unknown; unsigned int state; d11b_TableTail():state(0) {} };
struct d11b_TableRecord { d11b_TablePointer pointer; unsigned int count; d11b_TableTail tail; d11b_TableRecord():count(0) {} };
extern unsigned int d11b_table_state_804b10b0;
extern d11b_TablePointer d11b_first_table_80473724[16],d11b_second_table_80473764[16],d11b_third_table_804738a4[16],d11b_fourth_table_804738e4[16];
extern d11b_TableRecord d11b_records_804737a4[16];
extern "C" void d11b_init_tables_802cd308(int initialize,int priority) {
    if(priority==0xffff && initialize) {
        d11b_table_state_804b10b0=0;
        new (d11b_first_table_80473724) d11b_TablePointer[16];
        new (d11b_second_table_80473764) d11b_TablePointer[16];
        new (d11b_records_804737a4) d11b_TableRecord[16];
        new (d11b_third_table_804738a4) d11b_TablePointer[16];
        new (d11b_fourth_table_804738e4) d11b_TablePointer[16];
    }
}
