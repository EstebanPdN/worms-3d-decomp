/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s11_radius_test_802b4820)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802B15E0 = 0x802b15e0;
fn_802B22E4 = 0x802b22e4;
fn_802E82C0 = 0x802e82c0;
lbl_803D7E14 = 0x803d7e14;
lbl_803D7E18 = 0x803d7e18;
SECTIONS {
  .text.s11_radius_test_802b4820 0x802b4820 : { *(.text.s11_radius_test_802b4820) }
  .sdata 0x804abb4c (NOLOAD) : {
    . = 0x0; lbl_804ABB4C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
