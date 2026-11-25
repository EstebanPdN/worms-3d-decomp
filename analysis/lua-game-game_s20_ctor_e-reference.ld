/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_construct_flags_801902e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_803426b8 = 0x803426b8;
lbl_80413210 = 0x80413210;
lbl_80413270 = 0x80413270;
lbl_804132e0 = 0x804132e0;
lbl_80413338 = 0x80413338;
SECTIONS {
  .text.w3d_s20_construct_flags_801902e8 0x801902e8 : { *(.text.w3d_s20_construct_flags_801902e8) }
  .text.w3d_s20_construct_cleared_80190800 0x80190800 : { *(.text.w3d_s20_construct_cleared_80190800) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
