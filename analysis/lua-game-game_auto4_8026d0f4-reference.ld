/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8026d0f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800A830C = 0x800a830c;
fn_801298CC = 0x801298cc;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_8016293C = 0x8016293c;
fn_8026D2D8 = 0x8026d2d8;
fn_8026D328 = 0x8026d328;
fn_8026DA58 = 0x8026da58;
fn_80287760 = 0x80287760;
fn_80287830 = 0x80287830;
fn_802ABFFC = 0x802abffc;
fn_802ACA28 = 0x802aca28;
SECTIONS {
  .text.w3d_auto_8026d0f4 0x8026d0f4 : { *(.text.w3d_auto_8026d0f4) }
  .text.w3d_auto_802874dc 0x802874dc : { *(.text.w3d_auto_802874dc) }
  .text.w3d_auto_802abedc 0x802abedc : { *(.text.w3d_auto_802abedc) }
  .text.w3d_auto_802abf58 0x802abf58 : { *(.text.w3d_auto_802abf58) }
  .sdata 0x804b0ad8 (NOLOAD) : {
    . = 0x0; lbl_804B0AD8 = .;
    . = 0xf4; lbl_804B0BCC = .;
    . = 0x11c; lbl_804B0BF4 = .;
    . = 0x124; lbl_804B0BFC = .;
    . = 0x12c; lbl_804B0C04 = .;
    . = 0xcb0; lbl_804B1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
