/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802a282c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80296410 = 0x80296410;
fn_802E85FC = 0x802e85fc;
fn_802E87D4 = 0x802e87d4;
lbl_803D1FD0 = 0x803d1fd0;
SECTIONS {
  .text.w3d_auto_802a282c 0x802a282c : { *(.text.w3d_auto_802a282c) }
  .rodata 0x803d1fc8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
