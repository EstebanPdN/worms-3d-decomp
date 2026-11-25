/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_construct_80225ef0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ea0ec = 0x801ea0ec;
lbl_8041a2a8 = 0x8041a2a8;
SECTIONS {
  .text.w3d_s21_construct_80225ef0 0x80225ef0 : { *(.text.w3d_s21_construct_80225ef0) }
  .sdata 0x804b05b0 (NOLOAD) : {
    . = 0x0; lbl_804b05b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
