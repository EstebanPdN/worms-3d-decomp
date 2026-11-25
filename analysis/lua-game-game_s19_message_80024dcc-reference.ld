/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_handle_message_80024dcc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80024ea0 = 0x80024ea0;
FUN_801613f0 = 0x801613f0;
lbl_8040db38 = 0x8040db38;
w3d_auto_80024f64 = 0x80024f64;
w3d_auto_8015fb34 = 0x8015fb34;
w3d_cached_message_id = 0x8015f5a0;
w3d_message_id_equals_cache = 0x8015f65c;
w3d_message_post_current = 0x8016239c;
w3d_set_handle_owner_80024f00 = 0x80024f00;
SECTIONS {
  .text.s19_handle_message_80024dcc 0x80024dcc : { *(.text.s19_handle_message_80024dcc) }
  .sdata 0x804aca8c (NOLOAD) : {
    . = 0x0; lbl_804aca8c = .;
    . = 0x8; lbl_804aca94 = .;
    . = 0x4cc8; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
