/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19d_texgen_scale_offset_8016c130)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80302b60 = 0x80302b60;
fn_80307e24 = 0x80307e24;
fn_8030c0c8 = 0x8030c0c8;
lbl_803a56b0 = 0x803a56b0;
SECTIONS {
  .text.d19d_texgen_scale_offset_8016c130 0x8016c130 : { *(.text.d19d_texgen_scale_offset_8016c130) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; lbl_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
