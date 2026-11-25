/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_finish_801e65a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e45f0 = 0x801e45f0;
fn_801e5fd4 = 0x801e5fd4;
fn_801e6bbc = 0x801e6bbc;
SECTIONS {
  .text.w3d_s21_finish_801e65a0 0x801e65a0 : { *(.text.w3d_s21_finish_801e65a0) }
  .sdata 0x804ab85c (NOLOAD) : {
    . = 0x0; lbl_804ab85c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
