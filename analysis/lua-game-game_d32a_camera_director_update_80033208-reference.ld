/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32a_camera_director_update_80033208)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80035528 = 0x80035528;
g_msg_table_8040db38 = 0x8040db38;
s19_send_range_800336d0 = 0x800336d0;
s19_set_priority_flags_80032c18 = 0x80032c18;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_80032bb0 = 0x80032bb0;
w3d_auto_800359e4 = 0x800359e4;
w3d_auto_80108224 = 0x80108224;
w3d_auto_80178df0 = 0x80178df0;
w3d_cached_message_id = 0x8015f5a0;
w3d_logic_hook_800c88c4 = 0x800c88c4;
w3d_message_post_current = 0x8016239c;
SECTIONS {
  .text.w3d_d32a_camera_director_update_80033208 0x80033208 : { *(.text.w3d_d32a_camera_director_update_80033208) }
  .rodata 0x80373304 : { *(.rodata) }
  .sdata 0x804acf24 (NOLOAD) : {
    . = 0x0; g_id_804acf24 = .;
    . = 0x8; g_id_804acf2c = .;
    . = 0x4830; g_arena_804b1754 = .;
    . = 0x4864; g_engine_804b1788 = .;
    . = 0x4870; g_hook_804b1794 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
