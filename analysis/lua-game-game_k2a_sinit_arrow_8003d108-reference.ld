/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k2a_sinit_arrow_8003d108)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8003b92c = 0x8003b92c;
__16W3dType_80160038PvN21ii = 0x80160038;
w3d_arrow_804273c8 = 0x804273c8;
w3d_cached_message_name_init = 0x8015f518;
w3d_f32_80374580 = 0x80374580;
w3d_f32_80374584 = 0x80374584;
w3d_str_803617d0 = 0x803617d0;
w3d_str_80374488 = 0x80374488;
w3d_str_8037449c = 0x8037449c;
w3d_str_803744b4 = 0x803744b4;
w3d_str_803744cc = 0x803744cc;
w3d_str_803744e4 = 0x803744e4;
w3d_str_803744f8 = 0x803744f8;
w3d_str_80374514 = 0x80374514;
w3d_str_8037452c = 0x8037452c;
w3d_str_80374548 = 0x80374548;
w3d_str_80374564 = 0x80374564;
w3d_str_803e79d0 = 0x803e79d0;
w3d_type_8035ffa0 = 0x8035ffa0;
SECTIONS {
  .text.k2a_sinit_arrow_8003d108 0x8003d108 : { *(.text.k2a_sinit_arrow_8003d108) }
  .sdata 0x804ad138 (NOLOAD) : {
    . = 0x0; w3d_message_804ad138 = .;
    . = 0x8; w3d_message_804ad140 = .;
    . = 0x10; w3d_message_804ad148 = .;
    . = 0x18; w3d_message_804ad150 = .;
    . = 0x20; w3d_message_804ad158 = .;
    . = 0x28; w3d_message_804ad160 = .;
    . = 0x30; w3d_message_804ad168 = .;
    . = 0x38; w3d_message_804ad170 = .;
    . = 0x40; w3d_message_804ad178 = .;
    . = 0x48; w3d_message_804ad180 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
