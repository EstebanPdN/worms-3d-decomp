/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d18a_register_path_command_800089c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d18a_allocate_80212fd4 = 0x80212fd4;
d18a_copy_802eee50 = 0x802eee50;
d18a_path_end_8041d3a0 = 0x8041d3a0;
d18a_randomize_80015910 = 0x80015910;
d18a_register_8002274c = 0x8002274c;
d18a_release_802134fc = 0x802134fc;
d18a_world_map_refresh_8001f2cc = 0x8001f2cc;
SECTIONS {
  .text.w3d_d18a_register_path_command_800089c8 0x800089c8 : { *(.text.w3d_d18a_register_path_command_800089c8) }
  .rodata 0x80369574 : { *(.rodata) }
  .sdata 0x804aa564 (NOLOAD) : {
    . = 0x0; d18a_commands_804aa564 = .;
    . = 0x28; d18a_path_end_set_804aa58c = .;
    . = 0x40; d18a_registry_804aa5a4 = .;
    . = 0x174; d18a_settings_804aa6d8 = .;
    . = 0x71f4; d18a_world_map_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
