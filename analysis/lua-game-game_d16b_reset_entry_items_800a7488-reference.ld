/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d16b_reset_entry_items_800a7488)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
k5a_message_text_send_800a7b24 = 0x800a7b24;
s19_send_float_800a7ca0 = 0x800a7ca0;
w3d_auto_800a7ab8 = 0x800a7ab8;
w3d_cached_message_id = 0x8015f5a0;
w3d_zero_80381490 = 0x80381490;
SECTIONS {
  .text.d16b_reset_entry_items_800a7488 0x800a7488 : { *(.text.d16b_reset_entry_items_800a7488) }
  .sdata 0x804ae298 (NOLOAD) : {
    . = 0x0; w3d_text_key_804ae298 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
