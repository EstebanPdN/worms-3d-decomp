/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d15b_apply_selection_event_800a6ff4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
k5a_message_text_send_800a7b24 = 0x800a7b24;
w3d_auto_800a7ab8 = 0x800a7ab8;
w3d_cached_message_id = 0x8015f5a0;
SECTIONS {
  .text.d15b_apply_selection_event_800a6ff4 0x800a6ff4 : { *(.text.d15b_apply_selection_event_800a6ff4) }
  .sdata 0x804ae290 (NOLOAD) : {
    . = 0x0; w3d_select_key_804ae290 = .;
    . = 0x8; w3d_text_key_804ae298 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
