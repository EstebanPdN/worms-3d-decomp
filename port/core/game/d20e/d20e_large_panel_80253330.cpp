#include "w3d_ptr.h"
#line 1 "d20e_large_panel_80253330.cpp"
// Large front-end panel subclass constructor (Worms 3D GameCube PAL, 0x80253330).
//
// Runs the panel base constructor 0x80251f40 with the caller's 16-bit id,
// installs the subclass table 0x8041ba90 and initializes the members from
// +164 to +540 in declaration order: a zero vector, zero floats and ints,
// strings copy-constructed from the shared empty string 0x804b06a0
// (retaining it), and at +232 a reference to the shared object held in the
// global pointer 0x804b05b0, retained through the fourth slot of its table
// when non-null.
//
// Class and member names are structural; offsets are observed from the
// original instructions. The panel base (admitted separately as d19e) is
// declared here as an opaque out-of-line constructor; the table slot is
// declared, not defined, so the table stays an external object. Built with
// -mps-float (one saved FPR in a non-leaf function).
//
// Two declarations carry type information that the original scheduling
// depends on: the shared object global is a plain pointer (a scalar at a
// fixed address), and the string header returned by 0x80341884 is a
// structure whose first member is the 16-bit reference count. GCC 2.95 then
// knows the global read cannot alias the reference-count store and loads it
// before that store, as the original does.
struct D20ePanelRoot {
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN13D20ePanelRoot5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D20ePanelRoot, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D20ePanelRoot; };
struct D20ePanel : D20ePanelRoot {
    unsigned char body[160] __attribute__((aligned(__alignof__(D20ePanelRoot))));
    D20ePanel(unsigned short id);
};
extern "C" void w3d_string_base_init(Ptr32<void> string);
struct D20eStringHeader {
    unsigned short references;
};
extern "C" Ptr32<D20eStringHeader> w3d_string_header(Ptr32<void> string);
struct D20eString {
    Ptr32<char> text;
    D20eString(const D20eString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++w3d_string_header(this)->references;
    }
};
extern D20eString w3d_empty_string_804b06a0[];
struct D20eVec3 {
    float x, y, z;
    D20eVec3(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct D20eShared;
struct D20eSharedTable {
    Ptr32<void> slot0;
    Ptr32<void> slot4;
    Ptr32<void> slot8;
    Ptr32<void (Ptr32<D20eShared>)> retain;
};
struct D20eShared {
    Ptr32<D20eSharedTable> table;
};
struct D20eRef {
    Ptr32<D20eShared> object;
    template <class W3dU> D20eRef(Ptr32<W3dU> w3d_p) : D20eRef((D20eShared *)w3d_p.get()) {}
 D20eRef(D20eShared *shared) : object(shared)
    {
        if (object)
            object->table->retain(object);
    }
};
extern Ptr32<D20eShared> w3d_shared_object_804b05b0;
struct D20eLargePanel : D20ePanel {
    D20eVec3 vec164 __attribute__((aligned(__alignof__(D20ePanel))));
    float value176;
    float value180;
    float value184;
    float value188;
    float value192;
    D20eString text196;
    float value200;
    D20eString text204;
    D20eString text208;
    D20eString text212;
    D20eString text216;
    float value220;
    float value224;
    D20eString text228;
    D20eRef ref232;
    int value236;
    D20eString text240;
    float value244;
    float value248;
    float value252;
    int value256;
    float value260;
    float value264;
    int value268;
    float value272;
    int value276;
    float value280;
    D20eString text284;
    float value288;
    float value292;
    float value296;
    float value300;
    float value304;
    float value308;
    float value312;
    int value316;
    float value320;
    float value324;
    float value328;
    D20eString text332;
    float value336;
    D20eString text340;
    D20eString text344;
    D20eString text348;
    D20eString text352;
    D20eString text356;
    D20eString text360;
    float value364;
    D20eString text368;
    D20eString text372;
    D20eString text376;
    D20eString text380;
    D20eString text384;
    float value388;
    int value392;
    int value396;
    int value400;
    int value404;
    D20eString text408;
    D20eString text412;
    D20eString text416;
    int value420;
    D20eString text424;
    D20eString text428;
    D20eString text432;
    D20eString text436;
    D20eString text440;
    D20eString text444;
    int value448;
    int value452;
    int value456;
    int value460;
    int value464;
    int value468;
    int value472;
    int value476;
    int value480;
    int value484;
    int value488;
    int value492;
    int value496;
    int value500;
    int value504;
    int value508;
    int value512;
    int value516;
    int value520;
    int value524;
    int value528;
    int value532;
    int value536;
    int value540;
    D20eLargePanel(unsigned short id);
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN14D20eLargePanel5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { this->D20ePanel::slot0(); } };

D20eLargePanel::D20eLargePanel(unsigned short id)
    : D20ePanel(id),
      vec164(0, 0, 0),
      value176(0),
      value180(0),
      value184(0),
      value188(0),
      value192(0),
      text196(w3d_empty_string_804b06a0[0]),
      value200(0),
      text204(w3d_empty_string_804b06a0[0]),
      text208(w3d_empty_string_804b06a0[0]),
      text212(w3d_empty_string_804b06a0[0]),
      text216(w3d_empty_string_804b06a0[0]),
      value220(0),
      value224(0),
      text228(w3d_empty_string_804b06a0[0]),
      ref232(w3d_shared_object_804b05b0),
      value236(0),
      text240(w3d_empty_string_804b06a0[0]),
      value244(0),
      value248(0),
      value252(0),
      value256(0),
      value260(0),
      value264(0),
      value268(0),
      value272(0),
      value276(0),
      value280(0),
      text284(w3d_empty_string_804b06a0[0]),
      value288(0),
      value292(0),
      value296(0),
      value300(0),
      value304(0),
      value308(0),
      value312(0),
      value316(0),
      value320(0),
      value324(0),
      value328(0),
      text332(w3d_empty_string_804b06a0[0]),
      value336(0),
      text340(w3d_empty_string_804b06a0[0]),
      text344(w3d_empty_string_804b06a0[0]),
      text348(w3d_empty_string_804b06a0[0]),
      text352(w3d_empty_string_804b06a0[0]),
      text356(w3d_empty_string_804b06a0[0]),
      text360(w3d_empty_string_804b06a0[0]),
      value364(0),
      text368(w3d_empty_string_804b06a0[0]),
      text372(w3d_empty_string_804b06a0[0]),
      text376(w3d_empty_string_804b06a0[0]),
      text380(w3d_empty_string_804b06a0[0]),
      text384(w3d_empty_string_804b06a0[0]),
      value388(0),
      value392(0),
      value396(0),
      value400(0),
      value404(0),
      text408(w3d_empty_string_804b06a0[0]),
      text412(w3d_empty_string_804b06a0[0]),
      text416(w3d_empty_string_804b06a0[0]),
      value420(0),
      text424(w3d_empty_string_804b06a0[0]),
      text428(w3d_empty_string_804b06a0[0]),
      text432(w3d_empty_string_804b06a0[0]),
      text436(w3d_empty_string_804b06a0[0]),
      text440(w3d_empty_string_804b06a0[0]),
      text444(w3d_empty_string_804b06a0[0]),
      value448(0),
      value452(0),
      value456(0),
      value460(0),
      value464(0),
      value468(0),
      value472(0),
      value476(0),
      value480(0),
      value484(0),
      value488(0),
      value492(0),
      value496(0),
      value500(0),
      value504(0),
      value508(0),
      value512(0),
      value516(0),
      value520(0),
      value524(0),
      value528(0),
      value532(0),
      value536(0),
      value540(0)
{ W3D_SET_VPTR(this->D20ePanel::w3d_vptr_D20ePanelRoot, w3d_vt___vt_14D20eLargePanel, "__vt_14D20eLargePanel"); 
}


