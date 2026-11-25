/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_construct_8023a468)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80239d60 = 0x80239d60;
lbl_8041aea0 = 0x8041aea0;
SECTIONS {
  .text.w3d_s21_construct_8023a468 0x8023a468 : { *(.text.w3d_s21_construct_8023a468) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
