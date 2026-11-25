/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc43a_initialize_render_8016f93c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc43a_channelCodes_803fe3c0 = 0x803fe3c0;
cc43a_matrix_804559ac = 0x804559ac;
cc43a_ortho_80302ec4 = 0x80302ec4;
SECTIONS {
  .text.cc43a_initialize_render_8016f93c 0x8016f93c : { *(.text.cc43a_initialize_render_8016f93c) }
  .rodata 0x803a64e4 : { *(.rodata) }
  .sdata 0x804b1894 (NOLOAD) : {
    . = 0x0; cc43a_setup_804b1894 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
