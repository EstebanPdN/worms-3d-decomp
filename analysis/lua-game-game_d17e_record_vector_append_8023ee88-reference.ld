/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d17e_load_entries_8023ee88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_vt.14D17eNamedEntry = 0x804104e0;
_vt.9D17eEntry = 0x80410500;
w3d_array_read_80240be4 = 0x80240be4;
w3d_array_read_80240cb4 = 0x80240cb4;
w3d_array_read_80240d84 = 0x80240d84;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_default = 0x803426b8;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_d17e_load_entries_8023ee88 0x8023ee88 : { *(.text.w3d_d17e_load_entries_8023ee88) }
  .text.w3d_d17e_load_named_entries_8023f128 0x8023f128 : { *(.text.w3d_d17e_load_named_entries_8023f128) }
  .sdata 0x804aaf48 (NOLOAD) : {
    . = 0x0; lbl_804aaf48 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
