/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_chute_logic_step_800da388)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_chute_open_800da4e4 = 0x800da4e4;
w3d_f32_80389768 = 0x80389768;
w3d_getf_800dc0ac = 0x800dc0ac;
w3d_int_message_init_80125fdc = 0x80125fdc;
w3d_message_allocate_801613f0 = 0x801613f0;
w3d_message_post_current = 0x8016239c;
w3d_owner_resolve_80164fc8 = 0x80164fc8;
SECTIONS {
  .text.w3d_chute_logic_step_800da388 0x800da388 : { *(.text.w3d_chute_logic_step_800da388) }
  .text.w3d_chute_logic_value_800da4a8 0x800da4a8 : { *(.text.w3d_chute_logic_value_800da4a8) }
  .text.w3d_chute_close_800da750 0x800da750 : { *(.text.w3d_chute_close_800da750) }
  .sdata 0x804aeb94 (NOLOAD) : {
    . = 0x0; w3d_chute_name_804aeb94 = .;
    . = 0x2bc0; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
