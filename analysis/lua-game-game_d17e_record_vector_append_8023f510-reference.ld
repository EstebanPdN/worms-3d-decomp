/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d17e_load_int_entries_8023f510)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_vt.12D17eIntEntry = 0x804104f0;
_vt.14D17eFloatEntry = 0x804104c0;
_vt.16D17eIntPairEntry = 0x804104d0;
_vt.18D17eFloatPairEntry = 0x804104b0;
_vt.9D17eEntry = 0x80410500;
w3d_array_read_80240be4 = 0x80240be4;
w3d_array_read_80240cb4 = 0x80240cb4;
w3d_array_read_80240e54 = 0x80240e54;
w3d_array_read_80240f24 = 0x80240f24;
w3d_array_read_80240ff4 = 0x80240ff4;
w3d_array_read_802410c4 = 0x802410c4;
w3d_array_read_80241194 = 0x80241194;
w3d_array_read_80241264 = 0x80241264;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_d17e_load_int_entries_8023f510 0x8023f510 : { *(.text.w3d_d17e_load_int_entries_8023f510) }
  .text.w3d_d17e_load_int_pair_entries_8023f808 0x8023f808 : { *(.text.w3d_d17e_load_int_pair_entries_8023f808) }
  .text.w3d_d17e_load_float_entries_8023fb48 0x8023fb48 : { *(.text.w3d_d17e_load_float_entries_8023fb48) }
  .text.w3d_d17e_load_float_pair_entries_8023fe40 0x8023fe40 : { *(.text.w3d_d17e_load_float_pair_entries_8023fe40) }
  .sdata 0x804aaf48 (NOLOAD) : {
    . = 0x0; lbl_804aaf48 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
