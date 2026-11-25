/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_msg_handler_802c6dc8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_8015fb34 = 0x8015fb34;
w3d_fn_802c6f64 = 0x802c6f64;
w3d_fn_802c7014 = 0x802c7014;
SECTIONS {
  .text.w3d_msg_handler_802c6dc8 0x802c6dc8 : { *(.text.w3d_msg_handler_802c6dc8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
