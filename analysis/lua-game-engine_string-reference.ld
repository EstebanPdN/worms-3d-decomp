/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_string_allocate_header)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strlen = 0x802ef9c0;
w3d_heap_allocate = 0x802098d8;
w3d_heap_release = 0x80209920;
w3d_string_copy_bytes = 0x802eee50;
w3d_string_shared_empty = 0x804b06a0;
SECTIONS {
  .text.w3d_string_allocate_header 0x8020bae8 : { *(.text.w3d_string_allocate_header) }
  .text.w3d_string_release_header 0x8020bb2c : { *(.text.w3d_string_release_header) }
  .text.w3d_string_from_text 0x8020bb54 : { *(.text.w3d_string_from_text) }
  .text.w3d_string_allocate 0x8020bc88 : { *(.text.w3d_string_allocate) }
  .text.w3d_string_assign_text 0x8020bd58 : { *(.text.w3d_string_assign_text) }
  .text.w3d_string_assign_range 0x8020bdf4 : { *(.text.w3d_string_assign_range) }
  .text.w3d_string_base_init 0x8020c5c0 : { *(.text.w3d_string_base_init) }
  .text.w3d_string_base_finish 0x8020c5c4 : { *(.text.w3d_string_base_finish) }
  .text.w3d_string_release 0x80341588 : { *(.text.w3d_string_release) }
  .text.w3d_string_header 0x80341884 : { *(.text.w3d_string_header) }
  .text.w3d_string_default 0x803426b8 : { *(.text.w3d_string_default) }
  .text.w3d_string_header_data 0x80342728 : { *(.text.w3d_string_header_data) }
  .sdata 0x804aa6b8 (NOLOAD) : {
    . = 0x0; w3d_string_skip_base_ctor = .;
    . = 0x1364; w3d_string_empty_header = .;
    . = 0x5fec; w3d_string_heap = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
