/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s11_radius_test_80285d50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802B15E0 = 0x802b15e0;
fn_802B22E4 = 0x802b22e4;
fn_802E82C0 = 0x802e82c0;
lbl_803CF404 = 0x803cf404;
lbl_803CF408 = 0x803cf408;
SECTIONS {
  .text.s11_radius_test_80285d50 0x80285d50 : { *(.text.s11_radius_test_80285d50) }
  .sdata 0x804abb4c (NOLOAD) : {
    . = 0x0; lbl_804ABB4C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
