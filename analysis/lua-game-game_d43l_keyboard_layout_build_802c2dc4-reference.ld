/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d43l_keyboard_layout_build_802c2dc4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3StrPCc = 0x8020bb54;
fn_80164514 = 0x80164514;
fn_80178df0 = 0x80178df0;
fn_8020b680 = 0x8020b680;
fn_802b3020 = 0x802b3020;
fn_802b30c0 = 0x802b30c0;
fn_802b310c = 0x802b310c;
fn_802b3c5c = 0x802b3c5c;
fn_802b3d04 = 0x802b3d04;
fn_802c37e0 = 0x802c37e0;
fn_802c38cc = 0x802c38cc;
fn_802c61fc = 0x802c61fc;
fn_802c629c = 0x802c629c;
fn_802c6384 = 0x802c6384;
fn_802c6924 = 0x802c6924;
fn_802c71d8 = 0x802c71d8;
fn_802c7278 = 0x802c7278;
fn_802c72e4 = 0x802c72e4;
fn_802c7a0c = 0x802c7a0c;
fn_802c7cec = 0x802c7cec;
fn_802c813c = 0x802c813c;
type_8041c660 = 0x8041c660;
type_8041c910 = 0x8041c910;
type_8041c950 = 0x8041c950;
SECTIONS {
  .text.d43l_keyboard_layout_build_802c2dc4 0x802c2dc4 : { *(.text.d43l_keyboard_layout_build_802c2dc4) }
  .rodata 0x803d860c : { *(.rodata) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; scene_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
