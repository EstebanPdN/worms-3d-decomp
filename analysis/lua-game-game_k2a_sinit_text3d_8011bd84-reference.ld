/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k2a_sinit_text3d_8011bd84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8011a844 = 0x8011a844;
__16W3dType_80160038PvN21ii = 0x80160038;
w3d_cached_message_name_init = 0x8015f518;
w3d_str_803617d0 = 0x803617d0;
w3d_str_8039af80 = 0x8039af80;
w3d_str_803e8530 = 0x803e8530;
w3d_type_80361320 = 0x80361320;
SECTIONS {
  .text.k2a_sinit_text3d_8011bd84 0x8011bd84 : { *(.text.k2a_sinit_text3d_8011bd84) }
  .sdata 0x804af3a8 (NOLOAD) : {
    . = 0x0; w3d_message_804af3a8 = .;
    . = 0x8; w3d_byte_804af3b0 = .;
    . = 0x9; w3d_byte_804af3b1 = .;
    . = 0xa; w3d_byte_804af3b2 = .;
    . = 0xb; w3d_byte_804af3b3 = .;
    . = 0xc; w3d_byte_804af3b4 = .;
    . = 0xd; w3d_byte_804af3b5 = .;
    . = 0xe; w3d_byte_804af3b6 = .;
    . = 0xf; w3d_byte_804af3b7 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
