/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s11_radius_test_8025fbe8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802B15E0 = 0x802b15e0;
fn_802B22E4 = 0x802b22e4;
fn_802E82C0 = 0x802e82c0;
lbl_803CAB00 = 0x803cab00;
lbl_803CAB04 = 0x803cab04;
SECTIONS {
  .text.s11_radius_test_8025fbe8 0x8025fbe8 : { *(.text.s11_radius_test_8025fbe8) }
  .sdata 0x804abb4c (NOLOAD) : {
    . = 0x0; lbl_804ABB4C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
