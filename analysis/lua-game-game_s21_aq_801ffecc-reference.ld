/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_construct_801ffecc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ffe44 = 0x801ffe44;
lbl_80418cf0 = 0x80418cf0;
SECTIONS {
  .text.w3d_s21_construct_801ffecc 0x801ffecc : { *(.text.w3d_s21_construct_801ffecc) }
  .sdata 0x804b0638 (NOLOAD) : {
    . = 0x0; lbl_804b0638 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
