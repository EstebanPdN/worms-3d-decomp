// Borrowed GameCube ABI view: only observed control fields are described.
// This is not a complete or portable definition of the owning engine class.
#define MEMBER(p,T,n) (*(T*)((char*)(p)+(n)))
struct Control;
typedef void (*ControlMethod)(Control*, unsigned);
struct Control { ControlMethod* methods; };
union Color { unsigned word; unsigned char channels[4]; };
extern "C" void control_set_state_8025f064(Control*,unsigned);
extern "C" const Color* color_value_80178f54(void*);
extern "C" void color_assign_80173df0(void*,const Color*);
extern "C" void sol11c_control_states_8028c160(void* owner) {
    unsigned second = MEMBER(owner,unsigned,176);
    unsigned first = second ^ 1;
    unsigned third = MEMBER(owner,unsigned,140) ^ 1;
    if (MEMBER(owner,unsigned,140) == 0) {
        first = MEMBER(owner,Control*,240) == 0;
        second = 0;
    }
    Control* control = MEMBER(owner,Control*,232);
    if (control) control->methods[22](control,first);
    control = MEMBER(owner,Control*,236);
    if (control) control->methods[22](control,second);
    control = MEMBER(owner,Control*,240);
    if (control) control->methods[22](control,third);
    control = MEMBER(owner,Control*,212);
    if (control) control_set_state_8025f064(control,first);
    control = MEMBER(owner,Control*,216);
    if (control) control_set_state_8025f064(control,second);
    control = MEMBER(owner,Control*,220);
    if (control) control_set_state_8025f064(control,third);
    Color color = *color_value_80178f54(MEMBER(owner,void*,228));
    if (MEMBER(owner,unsigned,176)) color.channels[3] = 255;
    if (MEMBER(owner,void*,224)) color_assign_80173df0(MEMBER(owner,void*,224),&color);
}
