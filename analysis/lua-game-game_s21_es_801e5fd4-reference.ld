/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_is_busy_801e5fd4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e4444 = 0x801e4444;
fn_801e65fc = 0x801e65fc;
SECTIONS {
  .text.w3d_s21_is_busy_801e5fd4 0x801e5fd4 : { *(.text.w3d_s21_is_busy_801e5fd4) }
  .sdata 0x804ab85c (NOLOAD) : {
    . = 0x0; lbl_804ab85c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
