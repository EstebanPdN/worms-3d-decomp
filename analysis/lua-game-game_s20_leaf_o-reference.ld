/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_set_quad_801ab934)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_set_quad_801ab934 0x801ab934 : { *(.text.w3d_s20_set_quad_801ab934) }
  .text.w3d_s20_stamp_sequence_801afaa4 0x801afaa4 : { *(.text.w3d_s20_stamp_sequence_801afaa4) }
  .text.w3d_s20_get_pair_801c83fc 0x801c83fc : { *(.text.w3d_s20_get_pair_801c83fc) }
  .text.w3d_s20_set_quad_and_flag_801c8488 0x801c8488 : { *(.text.w3d_s20_set_quad_and_flag_801c8488) }
  .sdata 0x804ab788 (NOLOAD) : {
    . = 0x0; lbl_804ab788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
