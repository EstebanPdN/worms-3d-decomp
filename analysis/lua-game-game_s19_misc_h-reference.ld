/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_post_message_80021898)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800e8ee0 = 0x800e8ee0;
FUN_800e8f40 = 0x800e8f40;
FUN_800e9830 = 0x800e9830;
FUN_801613f0 = 0x801613f0;
FUN_801797b4 = 0x801797b4;
FUN_80341584 = 0x80341584;
lbl_8040db38 = 0x8040db38;
w3d_cached_message_id = 0x8015f5a0;
w3d_message_dispatch = 0x8015fc38;
SECTIONS {
  .text.s19_post_message_80021898 0x80021898 : { *(.text.s19_post_message_80021898) }
  .text.s19_init_from_config_8007070c 0x8007070c : { *(.text.s19_init_from_config_8007070c) }
  .sdata 0x804aca0c (NOLOAD) : {
    . = 0x0; lbl_804aca0c = .;
    . = 0x4d48; lbl_804b1754 = .;
    . = 0x4d54; lbl_804b1760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
