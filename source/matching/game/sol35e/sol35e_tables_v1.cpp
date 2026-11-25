// Observed static table constructor: four sixteen-element pointer tables and
// sixteen sixteen-byte records. Record offset eight is intentionally untouched.
inline void *operator new[](unsigned int,void *place) { return place; }
struct sol35e_d11b_TablePointer { void *value; sol35e_d11b_TablePointer():value(0) {} };
struct sol35e_d11b_TableTail { unsigned int unknown; unsigned int state; sol35e_d11b_TableTail():state(0) {} };
struct sol35e_d11b_TableRecord { sol35e_d11b_TablePointer pointer; unsigned int count; sol35e_d11b_TableTail tail; sol35e_d11b_TableRecord():count(0) {} };
sol35e_d11b_TablePointer sol35e_table_state_804b10b0;
sol35e_d11b_TablePointer sol35e_first_table_80473724[16];
sol35e_d11b_TablePointer sol35e_second_table_80473764[16];
sol35e_d11b_TableRecord sol35e_records_804737a4[16];
sol35e_d11b_TablePointer sol35e_third_table_804738a4[16];
sol35e_d11b_TablePointer sol35e_fourth_table_804738e4[16];
