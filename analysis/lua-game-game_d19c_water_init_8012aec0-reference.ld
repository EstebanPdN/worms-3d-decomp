/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19c_water_init_8012aec0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d19c_String_8020bb54PCc = 0x8020bb54;
d19c_cached_message_id_8015f5a0 = 0x8015f5a0;
d19c_engine_context_80165254 = 0x80165254;
d19c_handle_load_8015adf4 = 0x8015adf4;
d19c_mesh_reserve_indices_8018920c = 0x8018920c;
d19c_random_8015ff5c = 0x8015ff5c;
d19c_string_finish_8020c5c4 = 0x8020c5c4;
d19c_string_release_80341588 = 0x80341588;
d19c_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.d19c_water_init_8012aec0 0x8012aec0 : { *(.text.d19c_water_init_8012aec0) }
  .rodata 0x8039d2ac : { *(.rodata) }
  .sdata 0x804af608 (NOLOAD) : {
    . = 0x0; d19c_message_804af608 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
