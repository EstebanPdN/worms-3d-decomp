/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d16c_transition_mesh_801247d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d16c_String_8020bb54PCc = 0x8020bb54;
d16c_handle_load_8015adf4 = 0x8015adf4;
d16c_handle_mesh_80343584 = 0x80343584;
d16c_mesh_name_8039b868 = 0x8039b868;
d16c_one_8039b878 = 0x8039b878;
d16c_scale_8039b87c = 0x8039b87c;
d16c_string_finish_8020c5c4 = 0x8020c5c4;
d16c_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d16c_transition_mesh_801247d0 0x801247d0 : { *(.text.d16c_transition_mesh_801247d0) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; d16c_settings_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
