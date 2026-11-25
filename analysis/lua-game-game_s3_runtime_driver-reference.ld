/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_runtime_create_service)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_lookup_8020b680 = 0x8020b680;
w3d_object_80411238 = 0x80411238;
SECTIONS {
  .text.w3d_runtime_create_service 0x8015b904 : { *(.text.w3d_runtime_create_service) }
  .text.w3d_runtime_release_service 0x8015b9d0 : { *(.text.w3d_runtime_release_service) }
  .text.w3d_runtime_service_toggle 0x8015ba30 : { *(.text.w3d_runtime_service_toggle) }
  .text.w3d_runtime_handle_message 0x8015bcb0 : { *(.text.w3d_runtime_handle_message) }
  .text.w3d_runtime_service_finish 0x8015bd08 : { *(.text.w3d_runtime_service_finish) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
