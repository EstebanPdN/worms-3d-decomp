/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_post_camera_reset_8002c018)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_801613f0 = 0x801613f0;
lbl_8040db38 = 0x8040db38;
w3d_cached_message_id = 0x8015f5a0;
w3d_message_post_current = 0x8016239c;
SECTIONS {
  .text.s19_post_camera_reset_8002c018 0x8002c018 : { *(.text.s19_post_camera_reset_8002c018) }
  .sdata 0x804acc90 (NOLOAD) : {
    . = 0x0; lbl_804acc90 = .;
    . = 0x4ac4; lbl_804b1754 = .;
    . = 0x4af8; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
