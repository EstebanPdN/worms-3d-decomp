// Inferred editor lifetime layout with native member-array destruction.
struct F1pEditorIface{void**table;};struct F1pEditorHeld{F1pEditorIface*p;~F1pEditorHeld(){if(p)((void(*)(F1pEditorIface*))p->table[4])(p);}};
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct F1pEditorText{char*text;~F1pEditorText(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1pEditorBase_8015ff2c{void**table;char unknown[24];~F1pEditorBase_8015ff2c();};
struct F1pEditorMember_802afc40{char unknown[180];void*secondary;~F1pEditorMember_802afc40();};
struct F1pEditorNested_8026c860{char unknown[96];~F1pEditorNested_8026c860();};
struct F1pEditorOwner:F1pEditorBase_8015ff2c,F1pEditorMember_802afc40{F1pEditorHeld held212,held216;F1pEditorHeld pair0[2];F1pEditorHeld pair1[2];F1pEditorHeld pair2[2];F1pEditorHeld pair3[2];F1pEditorHeld pair4[2];F1pEditorHeld pair5[2];F1pEditorHeld pair6[2];F1pEditorHeld pair7[2];F1pEditorHeld held284;F1pEditorHeld pair288[2];F1pEditorHeld held296,held300;char unknown304[8];F1pEditorNested_8026c860 nested;F1pEditorHeld held408;char unknown412[12];F1pEditorText text424,text428;char unknown432[20];F1pEditorHeld held452;F1pEditorHeld held456;F1pEditorHeld held460;F1pEditorHeld held464;F1pEditorHeld held468;F1pEditorHeld held472;F1pEditorHeld held476;F1pEditorHeld held480;F1pEditorHeld held484;F1pEditorHeld held488;F1pEditorHeld held492;char unknown496[8];F1pEditorHeld held504,held508;~F1pEditorOwner();};
extern char vt_8041bc90[],vt_8041bce0[];
F1pEditorOwner::~F1pEditorOwner(){secondary=vt_8041bc90;table=(void**)vt_8041bce0;}
