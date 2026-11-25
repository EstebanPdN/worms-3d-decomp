/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30c_rope_mode_change_800cf028)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
campos_800cfcac = 0x800cfcac;
enter_800d0d6c = 0x800d0d6c;
exit_800d0e60 = 0x800d0e60;
fire_803880a8 = 0x803880a8;
init_8010a8e0 = 0x8010a8e0;
init_80126000 = 0x80126000;
memcpy_802eee50 = 0x802eee50;
msg_id_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
show_800cf2e8 = 0x800cf2e8;
ufire_803880b0 = 0x803880b0;
vel_800d0fa0 = 0x800d0fa0;
vt_8040db38 = 0x8040db38;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d30c_rope_mode_change_800cf028 0x800cf028 : { *(.text.d30c_rope_mode_change_800cf028) }
  .rodata 0x803880bc : { *(.rodata) }
  .sdata 0x804ae8c8 (NOLOAD) : {
    . = 0x0; id_804ae8c8 = .;
    . = 0x70; id_804ae938 = .;
    . = 0x80; id_804ae948 = .;
    . = 0x88; id_804ae950 = .;
    . = 0x98; id_804ae960 = .;
    . = 0xa0; id_804ae968 = .;
    . = 0xa8; id_804ae970 = .;
    . = 0xb0; id_804ae978 = .;
    . = 0x2e8c; heap_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
