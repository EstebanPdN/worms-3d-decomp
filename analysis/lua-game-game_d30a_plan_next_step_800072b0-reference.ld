/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30a_plan_next_step_800072b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80007080 = 0x80007080;
g_cost_table_8040cb40 = 0x8040cb40;
g_item_table_8040dc28 = 0x8040dc28;
memcpy_802eee50 = 0x802eee50;
w3d_ai_planner_reset = 0x80006694;
w3d_auto_8001523c = 0x8001523c;
w3d_command_create_19 = 0x80009404;
w3d_command_create_21 = 0x8000953c;
w3d_command_create_3 = 0x80008728;
w3d_command_create_6 = 0x80008d84;
w3d_cx9a_plan_create_append_80016ad0 = 0x80016ad0;
w3d_cx9a_storage_push_member_8002274c = 0x8002274c;
w3d_d17a_command_create_800085fc = 0x800085fc;
w3d_d28a_aim_command_create_80007eac = 0x80007eac;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
w3d_path_cost_construct = 0x80006360;
SECTIONS {
  .text.w3d_d30a_plan_next_step_800072b0 0x800072b0 : { *(.text.w3d_d30a_plan_next_step_800072b0) }
  .rodata 0x80369520 : { *(.rodata) }
  .sdata 0x804aa564 (NOLOAD) : {
    . = 0x0; g_items_804aa564 = .;
    . = 0x20; g_state_804aa584 = .;
    . = 0x24; g_count_804aa588 = .;
    . = 0x34; g_plan_804aa598 = .;
    . = 0x38; g_append_804aa59c = .;
    . = 0x3c; g_flag_804aa5a0 = .;
    . = 0x40; g_storage_804aa5a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
