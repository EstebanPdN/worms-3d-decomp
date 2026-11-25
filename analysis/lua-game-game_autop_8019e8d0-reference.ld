/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8019e8d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801D25EC = 0x801d25ec;
fn_801D2AAC = 0x801d2aac;
fn_801E6F0C = 0x801e6f0c;
fn_801EF380 = 0x801ef380;
fn_801F2798 = 0x801f2798;
fn_801FE1F8 = 0x801fe1f8;
fn_8020863C = 0x8020863c;
fn_80209E64 = 0x80209e64;
fn_8020BF2C = 0x8020bf2c;
fn_8020C5C4 = 0x8020c5c4;
fn_80210AFC = 0x80210afc;
fn_80271518 = 0x80271518;
fn_802B88B0 = 0x802b88b0;
fn_802BC93C = 0x802bc93c;
fn_802CD7F4 = 0x802cd7f4;
fn_802CDE08 = 0x802cde08;
fn_802DD10C = 0x802dd10c;
fn_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_auto_8019e8d0 0x8019e8d0 : { *(.text.w3d_auto_8019e8d0) }
  .text.w3d_auto_801d1fd4 0x801d1fd4 : { *(.text.w3d_auto_801d1fd4) }
  .text.w3d_auto_801d1ff8 0x801d1ff8 : { *(.text.w3d_auto_801d1ff8) }
  .text.w3d_auto_801d2138 0x801d2138 : { *(.text.w3d_auto_801d2138) }
  .text.w3d_auto_801d215c 0x801d215c : { *(.text.w3d_auto_801d215c) }
  .text.w3d_auto_801d229c 0x801d229c : { *(.text.w3d_auto_801d229c) }
  .text.w3d_auto_801d22c0 0x801d22c0 : { *(.text.w3d_auto_801d22c0) }
  .text.w3d_auto_801e6ec4 0x801e6ec4 : { *(.text.w3d_auto_801e6ec4) }
  .text.w3d_auto_801f2758 0x801f2758 : { *(.text.w3d_auto_801f2758) }
  .text.w3d_auto_80208a88 0x80208a88 : { *(.text.w3d_auto_80208a88) }
  .text.w3d_auto_80209d10 0x80209d10 : { *(.text.w3d_auto_80209d10) }
  .text.w3d_auto_8020c00c 0x8020c00c : { *(.text.w3d_auto_8020c00c) }
  .text.w3d_auto_80210abc 0x80210abc : { *(.text.w3d_auto_80210abc) }
  .text.w3d_auto_8026c860 0x8026c860 : { *(.text.w3d_auto_8026c860) }
  .text.w3d_auto_80276e04 0x80276e04 : { *(.text.w3d_auto_80276e04) }
  .text.w3d_auto_802b83ac 0x802b83ac : { *(.text.w3d_auto_802b83ac) }
  .sdata 0x804ab728 (NOLOAD) : {
    . = 0x0; lbl_804AB728 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
