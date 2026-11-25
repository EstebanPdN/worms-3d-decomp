/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_set_volume_801e5820)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801df288 = 0x801df288;
fn_80322838 = 0x80322838;
lbl_803b072c = 0x803b072c;
lbl_803b0730 = 0x803b0730;
SECTIONS {
  .text.w3d_s21_set_volume_801e5820 0x801e5820 : { *(.text.w3d_s21_set_volume_801e5820) }
  .sdata 0x804ab80c (NOLOAD) : {
    . = 0x0; lbl_804ab80c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
