#include "w3d_ptr.h"
#line 1 "d26b_scheme_load_8008cf40.cpp"
/* Scheme data load (0x8008cf40): looks up the property "GM.SchemeData" (0x800fc330), resets
 * the weapon table 0x80431c80 (count 0 and index for 39 and 20 entries), then copies the
 * scheme value of each enabled setting (+32 not -1, value +28) into its entry, or in the
 * fallback mode writes a fixed count for it, and finally clears seven entries that are
 * never available. Names are inferred from the original instructions. Owns the name
 * string at 0x8037daf4. */
struct PropertyKey { Ptr32<const char> name; };
struct Setting { char unknown00[28]; int value; int enabled; };
struct Info { Ptr32<Setting> settings[1]; };
struct Entry { int count; int index; };
extern Entry w3d_weapon_table_80431c80[];
extern Entry w3d_weapon_table_80431db8[];
extern "C" int w3d_auto_800fc330(Ptr32<PropertyKey>, Ptr32<Ptr32<Info>>);
extern "C" void w3d_d26b_scheme_load_8008cf40(Ptr32<void> self, int fallback)
{
    PropertyKey key;
    Ptr32<Info> info;
    key.name = "GM.SchemeData";
    w3d_auto_800fc330(&key, &info);
    Ptr32<Info> s = info;
    {
        Ptr32<Entry> e = w3d_weapon_table_80431c80;
        for (int i = 0; i < 39; i++) { e->index = i; e->count = 0; e++; }
    }
    {
        Ptr32<Entry> e = w3d_weapon_table_80431db8;
        for (int i = 0; i < 20; i++) { e->count = 0; e->index = i + 39; e++; }
    }
    if (fallback == 0) {
        if (s->settings[16]->enabled != -1) w3d_weapon_table_80431c80[0].count = s->settings[16]->value;
        if (s->settings[38]->enabled != -1) w3d_weapon_table_80431c80[1].count = s->settings[38]->value;
        if (s->settings[12]->enabled != -1) w3d_weapon_table_80431c80[2].count = s->settings[12]->value;
        if (s->settings[20]->enabled != -1) w3d_weapon_table_80431c80[3].count = s->settings[20]->value;
        if (s->settings[25]->enabled != -1) w3d_weapon_table_80431c80[4].count = s->settings[25]->value;
        if (s->settings[37]->enabled != -1) w3d_weapon_table_80431c80[5].count = s->settings[37]->value;
        if (s->settings[18]->enabled != -1) w3d_weapon_table_80431c80[6].count = s->settings[18]->value;
        if (s->settings[33]->enabled != -1) w3d_weapon_table_80431c80[7].count = s->settings[33]->value;
        if (s->settings[53]->enabled != -1) w3d_weapon_table_80431c80[8].count = s->settings[53]->value;
        if (s->settings[48]->enabled != -1) w3d_weapon_table_80431c80[9].count = s->settings[48]->value;
        if (s->settings[17]->enabled != -1) w3d_weapon_table_80431c80[10].count = s->settings[17]->value;
        if (s->settings[59]->enabled != -1) w3d_weapon_table_80431c80[11].count = s->settings[59]->value;
        if (s->settings[47]->enabled != -1) w3d_weapon_table_80431c80[12].count = s->settings[47]->value;
        if (s->settings[42]->enabled != -1) w3d_weapon_table_80431c80[13].count = s->settings[42]->value;
        if (s->settings[36]->enabled != -1) w3d_weapon_table_80431c80[14].count = s->settings[36]->value;
        if (s->settings[23]->enabled != -1) w3d_weapon_table_80431c80[15].count = s->settings[23]->value;
        if (s->settings[35]->enabled != -1) w3d_weapon_table_80431c80[16].count = s->settings[35]->value;
        if (s->settings[24]->enabled != -1) w3d_weapon_table_80431c80[17].count = s->settings[24]->value;
        if (s->settings[55]->enabled != -1) w3d_weapon_table_80431c80[18].count = s->settings[55]->value;
        w3d_weapon_table_80431c80[19].count = 0;
        if (s->settings[60]->enabled != -1) w3d_weapon_table_80431c80[20].count = s->settings[60]->value;
        if (s->settings[40]->enabled != -1) w3d_weapon_table_80431c80[21].count = s->settings[40]->value;
        w3d_weapon_table_80431c80[22].count = 0;
        if (s->settings[29]->enabled != -1) w3d_weapon_table_80431c80[23].count = s->settings[29]->value;
        if (s->settings[62]->enabled != -1) w3d_weapon_table_80431c80[24].count = s->settings[62]->value;
        if (s->settings[11]->enabled != -1) w3d_weapon_table_80431c80[25].count = s->settings[11]->value;
        if (s->settings[43]->enabled != -1) w3d_weapon_table_80431c80[26].count = s->settings[43]->value;
        w3d_weapon_table_80431c80[27].count = 0;
        w3d_weapon_table_80431c80[28].count = 0;
        if (s->settings[50]->enabled != -1) w3d_weapon_table_80431c80[29].count = s->settings[50]->value;
        if (s->settings[73]->enabled != -1) w3d_weapon_table_80431c80[30].count = s->settings[73]->value;
        if (s->settings[31]->enabled != -1) w3d_weapon_table_80431c80[31].count = s->settings[31]->value;
        if (s->settings[8]->enabled != -1) w3d_weapon_table_80431c80[32].count = s->settings[8]->value;
        if (s->settings[27]->enabled != -1) w3d_weapon_table_80431c80[33].count = s->settings[27]->value;
        if (s->settings[51]->enabled != -1) w3d_weapon_table_80431c80[34].count = s->settings[51]->value;
        if (s->settings[15]->enabled != -1) w3d_weapon_table_80431c80[35].count = s->settings[15]->value;
        if (s->settings[39]->enabled != -1) w3d_weapon_table_80431db8[0].count = s->settings[39]->value;
        if (s->settings[13]->enabled != -1) w3d_weapon_table_80431db8[1].count = s->settings[13]->value;
        if (s->settings[22]->enabled != -1) w3d_weapon_table_80431db8[2].count = s->settings[22]->value;
        if (s->settings[61]->enabled != -1) w3d_weapon_table_80431db8[3].count = s->settings[61]->value;
        if (s->settings[57]->enabled != -1) w3d_weapon_table_80431db8[4].count = s->settings[57]->value;
        if (s->settings[30]->enabled != -1) w3d_weapon_table_80431db8[5].count = s->settings[30]->value;
        if (s->settings[58]->enabled != -1) w3d_weapon_table_80431db8[6].count = s->settings[58]->value;
        w3d_weapon_table_80431db8[7].count = 0;
        if (s->settings[49]->enabled != -1) w3d_weapon_table_80431db8[8].count = s->settings[49]->value;
        if (s->settings[34]->enabled != -1) w3d_weapon_table_80431db8[9].count = s->settings[34]->value;
        w3d_weapon_table_80431db8[10].count = 0;
        w3d_weapon_table_80431db8[11].count = 0;
        if (s->settings[56]->enabled != -1) w3d_weapon_table_80431db8[12].count = s->settings[56]->value;
        if (s->settings[41]->enabled != -1) w3d_weapon_table_80431db8[13].count = s->settings[41]->value;
        if (s->settings[7]->enabled != -1) w3d_weapon_table_80431db8[15].count = s->settings[7]->value;
        if (s->settings[6]->enabled != -1) w3d_weapon_table_80431db8[16].count = s->settings[6]->value;
        if (s->settings[10]->enabled != -1) w3d_weapon_table_80431db8[17].count = s->settings[10]->value;
        if (s->settings[9]->enabled != -1) w3d_weapon_table_80431db8[18].count = s->settings[9]->value;
        if (s->settings[46]->enabled != -1) w3d_weapon_table_80431db8[14].count = s->settings[46]->value;
    } else {
        if (s->settings[16]->enabled != -1) w3d_weapon_table_80431c80[0].count = 4;
        if (s->settings[38]->enabled != -1) w3d_weapon_table_80431c80[1].count = 4;
        if (s->settings[12]->enabled != -1) w3d_weapon_table_80431c80[2].count = 4;
        if (s->settings[20]->enabled != -1) w3d_weapon_table_80431c80[3].count = 3;
        if (s->settings[25]->enabled != -1) w3d_weapon_table_80431c80[4].count = 4;
        if (s->settings[37]->enabled != -1) w3d_weapon_table_80431c80[5].count = 2;
        if (s->settings[18]->enabled != -1) w3d_weapon_table_80431c80[6].count = 2;
        if (s->settings[33]->enabled != -1) w3d_weapon_table_80431c80[7].count = 4;
        if (s->settings[53]->enabled != -1) w3d_weapon_table_80431c80[8].count = 4;
        if (s->settings[48]->enabled != -1) w3d_weapon_table_80431c80[9].count = 4;
        if (s->settings[17]->enabled != -1) w3d_weapon_table_80431c80[10].count = 3;
        if (s->settings[59]->enabled != -1) w3d_weapon_table_80431c80[11].count = 4;
        if (s->settings[47]->enabled != -1) w3d_weapon_table_80431c80[12].count = 4;
        if (s->settings[42]->enabled != -1) w3d_weapon_table_80431c80[13].count = 3;
        if (s->settings[36]->enabled != -1) w3d_weapon_table_80431c80[14].count = 2;
        if (s->settings[23]->enabled != -1) w3d_weapon_table_80431c80[15].count = 4;
        if (s->settings[35]->enabled != -1) w3d_weapon_table_80431c80[16].count = 4;
        if (s->settings[24]->enabled != -1) w3d_weapon_table_80431c80[17].count = 1;
        if (s->settings[55]->enabled != -1) w3d_weapon_table_80431c80[18].count = 4;
        w3d_weapon_table_80431c80[19].count = 0;
        if (s->settings[60]->enabled != -1) w3d_weapon_table_80431c80[20].count = 4;
        if (s->settings[40]->enabled != -1) w3d_weapon_table_80431c80[21].count = 3;
        w3d_weapon_table_80431c80[22].count = 0;
        if (s->settings[29]->enabled != -1) w3d_weapon_table_80431c80[23].count = 2;
        if (s->settings[62]->enabled != -1) w3d_weapon_table_80431c80[24].count = 2;
        if (s->settings[11]->enabled != -1) w3d_weapon_table_80431c80[25].count = 1;
        if (s->settings[43]->enabled != -1) w3d_weapon_table_80431c80[26].count = 1;
        w3d_weapon_table_80431c80[27].count = 0;
        w3d_weapon_table_80431c80[28].count = 0;
        if (s->settings[50]->enabled != -1) w3d_weapon_table_80431c80[29].count = 2;
        if (s->settings[73]->enabled != -1) w3d_weapon_table_80431c80[30].count = 3;
        if (s->settings[31]->enabled != -1) w3d_weapon_table_80431c80[31].count = 2;
        if (s->settings[8]->enabled != -1) w3d_weapon_table_80431c80[32].count = 2;
        if (s->settings[27]->enabled != -1) w3d_weapon_table_80431c80[33].count = 1;
        if (s->settings[51]->enabled != -1) w3d_weapon_table_80431c80[34].count = 4;
        if (s->settings[15]->enabled != -1) w3d_weapon_table_80431c80[35].count = 4;
        if (s->settings[39]->enabled != -1) w3d_weapon_table_80431db8[0].count = 4;
        if (s->settings[13]->enabled != -1) w3d_weapon_table_80431db8[1].count = 2;
        if (s->settings[22]->enabled != -1) w3d_weapon_table_80431db8[2].count = 4;
        if (s->settings[61]->enabled != -1) w3d_weapon_table_80431db8[3].count = 4;
        if (s->settings[57]->enabled != -1) w3d_weapon_table_80431db8[4].count = 2;
        if (s->settings[30]->enabled != -1) w3d_weapon_table_80431db8[5].count = 3;
        if (s->settings[58]->enabled != -1) w3d_weapon_table_80431db8[6].count = 3;
        w3d_weapon_table_80431db8[7].count = 0;
        if (s->settings[49]->enabled != -1) w3d_weapon_table_80431db8[8].count = 4;
        if (s->settings[34]->enabled != -1) w3d_weapon_table_80431db8[9].count = 2;
        w3d_weapon_table_80431db8[10].count = 0;
        w3d_weapon_table_80431db8[11].count = 0;
        if (s->settings[56]->enabled != -1) w3d_weapon_table_80431db8[12].count = 3;
        if (s->settings[41]->enabled != -1) w3d_weapon_table_80431db8[13].count = 3;
        if (s->settings[7]->enabled != -1) w3d_weapon_table_80431db8[15].count = 1;
        if (s->settings[6]->enabled != -1) w3d_weapon_table_80431db8[16].count = 1;
        if (s->settings[10]->enabled != -1) w3d_weapon_table_80431db8[17].count = 1;
        if (s->settings[9]->enabled != -1) w3d_weapon_table_80431db8[18].count = 2;
        if (s->settings[46]->enabled != -1) w3d_weapon_table_80431db8[14].count = 1;
    }
}


