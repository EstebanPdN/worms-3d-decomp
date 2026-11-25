/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_string_append)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strlen = 0x802ef9c0;
w3d_string_allocate = 0x8020bc88;
w3d_string_copy_bytes = 0x802eee50;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_string_append 0x8020bf2c : { *(.text.w3d_string_append) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
