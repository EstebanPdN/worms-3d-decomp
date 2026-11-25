/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30k_button_radius_test_80266234)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802b15e0 = 0x802b15e0;
fn_802b22e4 = 0x802b22e4;
fn_802e82c0 = 0x802e82c0;
lbl_803cb5c4 = 0x803cb5c4;
lbl_803cb5c8 = 0x803cb5c8;
SECTIONS {
  .text.w3d_d30k_button_radius_test_80266234 0x80266234 : { *(.text.w3d_d30k_button_radius_test_80266234) }
  .sdata 0x804abb4c (NOLOAD) : {
    . = 0x0; lbl_804abb4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
