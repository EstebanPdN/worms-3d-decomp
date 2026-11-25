/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27h_axis_input_dispatch_800a7148)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
k5a_message_text_send_800a7b24 = 0x800a7b24;
s19_send_float_800a7ca0 = 0x800a7ca0;
w3d_auto_800a7ab8 = 0x800a7ab8;
w3d_cached_message_id = 0x8015f5a0;
SECTIONS {
  .text.d27h_axis_input_dispatch_800a7148 0x800a7148 : { *(.text.d27h_axis_input_dispatch_800a7148) }
  .rodata 0x803813e0 : { *(.rodata) }
  .sdata 0x804ae290 (NOLOAD) : {
    . = 0x0; key_804ae290 = .;
    . = 0x8; key_804ae298 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
