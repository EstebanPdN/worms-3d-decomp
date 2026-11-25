/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d15b_flush_pending_messages_800a7fdc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
k5a_message_text_send_800a7b24 = 0x800a7b24;
s19_send_range_800a7d18 = 0x800a7d18;
w3d_auto_800a7c24 = 0x800a7c24;
w3d_cached_message_id = 0x8015f5a0;
SECTIONS {
  .text.d15b_flush_pending_messages_800a7fdc 0x800a7fdc : { *(.text.d15b_flush_pending_messages_800a7fdc) }
  .sdata 0x804ae298 (NOLOAD) : {
    . = 0x0; w3d_text_key_804ae298 = .;
    . = 0x8; w3d_range_key_804ae2a0 = .;
    . = 0x20; w3d_range_key_804ae2b8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
