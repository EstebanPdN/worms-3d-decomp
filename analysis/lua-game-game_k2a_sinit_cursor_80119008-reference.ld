/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k2a_sinit_cursor_80119008)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80118bf0 = 0x80118bf0;
__16W3dType_80160038PvN21ii = 0x80160038;
w3d_str_803617d0 = 0x803617d0;
w3d_str_803e84c0 = 0x803e84c0;
w3d_type_80361260 = 0x80361260;
SECTIONS {
  .text.k2a_sinit_cursor_80119008 0x80119008 : { *(.text.k2a_sinit_cursor_80119008) }
  .sdata 0x804af314 (NOLOAD) : {
    . = 0x0; w3d_color_804af314 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
