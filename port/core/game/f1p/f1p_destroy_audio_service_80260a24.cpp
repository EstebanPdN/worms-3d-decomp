#include "w3d_ptr.h"
#line 1 "f1p_destroy_audio_service_80260a24.cpp"
// Inferred service interfaces and observed stop/clear/destruction lifetimes.
struct F1pAudioIface{Ptr32<Ptr32<void>> table;};
struct F1pAudioHeld{Ptr32<F1pAudioIface> p;~F1pAudioHeld(){if(p)((Ptr32<void (Ptr32<F1pAudioIface>)>)p->table[4])(p);}template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((F1pAudioIface *)w3d_p.get()); }
 F1pAudioHeld&operator=(F1pAudioIface*other){if(p)((Ptr32<void (Ptr32<F1pAudioIface>)>)p->table[4])(p);p=other;return *this;}void stop(){if(p)((Ptr32<void (Ptr32<F1pAudioIface>)>)p->table[6])(p);}};
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct F1pAudioTitle{
 F1pAudioTitle(const F1pAudioTitle &); F1pAudioTitle() {}Ptr32<char> data;~F1pAudioTitle(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1pAudioBase_801628ec{Ptr32<Ptr32<void>> table;char unknown[24];~F1pAudioBase_801628ec();};
struct F1pAudioOwner:F1pAudioBase_801628ec{
F1pAudioHeld held28 __attribute__((aligned(__alignof__(F1pAudioBase_801628ec))));F1pAudioHeld held32;F1pAudioHeld held36;F1pAudioHeld held40;F1pAudioHeld held44;F1pAudioHeld held48;F1pAudioHeld held52;F1pAudioHeld held56;F1pAudioHeld held60;F1pAudioHeld held64;F1pAudioHeld held68;F1pAudioHeld held72;F1pAudioHeld held76;F1pAudioHeld held80;F1pAudioHeld held84;F1pAudioHeld held88;F1pAudioHeld held92;F1pAudioHeld held96;F1pAudioHeld held100;F1pAudioHeld held104;F1pAudioHeld held108;F1pAudioHeld held112;F1pAudioHeld held116;F1pAudioHeld held120;F1pAudioHeld held124;F1pAudioHeld held128;F1pAudioHeld held132;F1pAudioHeld held136;F1pAudioHeld held140;F1pAudioHeld held144;F1pAudioHeld held148;F1pAudioHeld held152;F1pAudioHeld held156;F1pAudioHeld held160;F1pAudioHeld held164;F1pAudioHeld held168;F1pAudioHeld held172;
int state176;F1pAudioHeld held180;Ptr32<int> shared;float volume,timing;int state196;F1pAudioHeld held200,held204;int state208;F1pAudioTitle title;int slots[20];~F1pAudioOwner();};
extern char vt_8041bbc0[];extern Ptr32<F1pAudioOwner> instance_804abb44;
F1pAudioOwner::~F1pAudioOwner(){table=(Ptr32<Ptr32<void>>)vt_8041bbc0;held200.stop();held200=0;state208=3;held204.stop();held204=0;instance_804abb44=0;}


