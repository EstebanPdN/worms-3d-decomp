/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11b_request_storage_return_8020f660)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
append_8020f850 = 0x8020f850;
SECTIONS {
  .text.w3d_cx11b_request_storage_return_8020f660 0x8020f660 : { *(.text.w3d_cx11b_request_storage_return_8020f660) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
