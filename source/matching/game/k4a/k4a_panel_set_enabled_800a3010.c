struct K4aSwitch;
typedef struct K4aSwitchVtable { void (*unknown_00[22])(void); int (*set_enabled)(struct K4aSwitch *self, int enabled); } K4aSwitchVtable;
typedef struct K4aSwitch { const K4aSwitchVtable *vtable; } K4aSwitch;
typedef struct K4aPanel { char pad0[52]; K4aSwitch *second; K4aSwitch *first; K4aSwitch *third; char pad1[84]; int second_flag; char pad2[4]; void *first_source; } K4aPanel;
extern int w3d_auto_80178d1c(void *);

void k4a_panel_set_enabled_800a3010(K4aPanel *self, int enabled)
{
    int first_on = 0;
    K4aSwitch *first = self->first;
    const K4aSwitchVtable *first_vtable = first->vtable;
    K4aSwitch *second;
    const K4aSwitchVtable *second_vtable;
    int second_on;
    if (enabled != 0 && w3d_auto_80178d1c(self->first_source) != 0)
        first_on = 1;
    first_vtable->set_enabled(first, first_on);
    second = self->second;
    second_on = 0;
    second_vtable = second->vtable;
    if (enabled != 0 && self->second_flag != 0)
        second_on = 1;
    second_vtable->set_enabled(second, second_on);
    self->third->vtable->set_enabled(self->third, enabled);
}
