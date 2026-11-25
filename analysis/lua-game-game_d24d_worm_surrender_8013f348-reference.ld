/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_worm_surrender_8013f348)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__11d24d_StringPCc = 0x8020bb54;
d24d_draw_8039fda4 = 0x8039fda4;
d24d_flag_8039fd94 = 0x8039fd94;
d24d_handle_load_8015adf4 = 0x8015adf4;
d24d_mesh_of_80343584 = 0x80343584;
d24d_mesh_set_resource_value_80182410 = 0x80182410;
d24d_play_named_801359ec = 0x801359ec;
d24d_prod_8039f5a0 = 0x8039f5a0;
d24d_string_finish_8020c5c4 = 0x8020c5c4;
d24d_string_release_80341588 = 0x80341588;
strcmp = 0x802ef234;
SECTIONS {
  .text.d24d_worm_surrender_8013f348 0x8013f348 : { *(.text.d24d_worm_surrender_8013f348) }
  .rodata 0x8039fdb4 : { *(.rodata) }
  .sdata 0x804ab100 (NOLOAD) : {
    . = 0x0; d24d_idle_804ab100 = .;
    . = 0x228; d24d_attach_id_804ab328 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
