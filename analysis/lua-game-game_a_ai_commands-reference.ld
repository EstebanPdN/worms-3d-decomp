/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_command_create_1)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_alloc_8001523c = 0x8001523c;
w3d_command_register_8002274c = 0x8002274c;
w3d_command_set_count_80021838 = 0x80021838;
w3d_command_vtable_15_8040dbe8 = 0x8040dbe8;
w3d_command_vtable_17_8040dba8 = 0x8040dba8;
w3d_command_vtable_18_8040db88 = 0x8040db88;
w3d_command_vtable_19_8040db68 = 0x8040db68;
w3d_command_vtable_1_8040dd68 = 0x8040dd68;
w3d_command_vtable_21_8040db48 = 0x8040db48;
w3d_command_vtable_3_8040dd28 = 0x8040dd28;
w3d_command_vtable_6_8040dce8 = 0x8040dce8;
w3d_command_vtable_7_8040dcc8 = 0x8040dcc8;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
w3d_memcpy_802eee50 = 0x802eee50;
w3d_vec3_origin_8041d3a0 = 0x8041d3a0;
w3d_world_map_refresh_8001f2cc = 0x8001f2cc;
SECTIONS {
  .text.w3d_command_create_1 0x80007d58 : { *(.text.w3d_command_create_1) }
  .text.w3d_command_create_3 0x80008728 : { *(.text.w3d_command_create_3) }
  .text.w3d_command_create_7 0x80008c44 : { *(.text.w3d_command_create_7) }
  .text.w3d_command_create_6 0x80008d84 : { *(.text.w3d_command_create_6) }
  .text.w3d_command_create_15 0x80008ed4 : { *(.text.w3d_command_create_15) }
  .text.w3d_command_create_17 0x80009164 : { *(.text.w3d_command_create_17) }
  .text.w3d_command_create_18 0x800092bc : { *(.text.w3d_command_create_18) }
  .text.w3d_command_create_19 0x80009404 : { *(.text.w3d_command_create_19) }
  .text.w3d_command_create_21 0x8000953c : { *(.text.w3d_command_create_21) }
  .sdata 0x804aa564 (NOLOAD) : {
    . = 0x0; w3d_command_list_804aa564 = .;
    . = 0x20; w3d_ai_state_804aa584 = .;
    . = 0x28; w3d_ai_flag_804aa58c = .;
    . = 0x40; w3d_command_registry_804aa5a4 = .;
    . = 0x160; w3d_ai_team_804aa6c4 = .;
    . = 0x71f4; w3d_world_map_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
