/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27h_input_event_800a6c80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
flush_pending_800a7fdc = 0x800a7fdc;
k5a_message_text_send_800a7b24 = 0x800a7b24;
s19_send_range_800a7d18 = 0x800a7d18;
w3d_auto_800a7ab8 = 0x800a7ab8;
w3d_auto_800a7bb4 = 0x800a7bb4;
w3d_cached_message_id = 0x8015f5a0;
w3d_runtime_is_paused = 0x8015ccbc;
SECTIONS {
  .text.d27h_input_event_800a6c80 0x800a6c80 : { *(.text.d27h_input_event_800a6c80) }
  .rodata 0x80381380 : { *(.rodata) }
  .sdata 0x804ae290 (NOLOAD) : {
    . = 0x0; key_804ae290 = .;
    . = 0x8; key_804ae298 = .;
    . = 0x18; key_804ae2a8 = .;
    . = 0x20; key_804ae2b0 = .;
    . = 0x30; key_804ae2c0 = .;
    . = 0x38; key_804ae2c8 = .;
    . = 0x34f8; g_runtime_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
