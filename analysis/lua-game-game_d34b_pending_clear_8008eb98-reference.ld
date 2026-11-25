/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d34b_pending_clear_8008eb98)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_copy_802eee50 = 0x802eee50;
w3d_list_80431e88 = 0x80431e88;
w3d_list_80431e94 = 0x80431e94;
w3d_notify_801ef380 = 0x801ef380;
SECTIONS {
  .text.d34b_pending_clear_8008eb98 0x8008eb98 : { *(.text.d34b_pending_clear_8008eb98) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
