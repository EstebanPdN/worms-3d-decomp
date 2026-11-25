/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_construct_80237744)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ea0ec = 0x801ea0ec;
fn_8025d5a4 = 0x8025d5a4;
lbl_8041a748 = 0x8041a748;
SECTIONS {
  .text.w3d_s21_construct_80237744 0x80237744 : { *(.text.w3d_s21_construct_80237744) }
  .sdata 0x804b05ac (NOLOAD) : {
    . = 0x0; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
