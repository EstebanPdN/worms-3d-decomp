#include "w3d_ptr.h"
#line 1 "codex_flags_8006ee18.cpp"
struct T261State { char unknown[240]; unsigned int flags; };
extern Ptr32<T261State> t261_state_804aaabc;
extern "C" int t261_handles_8006e10c(Ptr32<T261State>);
extern "C" bool t261_check_8006ae58(Ptr32<T261State>);
extern "C" int w3d_fe_hold_mode_start(void);
extern "C" int codex_flags_8006ee18() {
 if(t261_state_804aaabc->flags & 0x04000000) return 0;
 if(t261_handles_8006e10c(t261_state_804aaabc)) return 0;
 if(t261_state_804aaabc->flags & 0x01000000) {
  // v42 (port): el paso del menú a la partida espera unos cuadros a que la pantalla de carga funda su icono
  // (core/native/fe_bridge.cpp, w3d_fe_hold_mode_start). Antes de la comprobación: no consume nada.
  if(w3d_fe_hold_mode_start()) return 0;
  return t261_check_8006ae58(t261_state_804aaabc)?1:0;
 }
 return 0;
}


