/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25b_girder_input_80094a84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_handle_member_query_8012629c = 0x8012629c;
SECTIONS {
  .text.w3d_d25b_girder_input_80094a84 0x80094a84 : { *(.text.w3d_d25b_girder_input_80094a84) }
  .rodata 0x8037ea70 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
