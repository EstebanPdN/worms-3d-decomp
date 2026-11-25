/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d43a_weapon_plan_issue_8000affc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80007eac = 0x80007eac;
cc24a_planner_influence_attenuation_800165cc = 0x800165cc;
cc25a_vector_elevation_angle_8001b734 = 0x8001b734;
s19_randomize_three_80015910 = 0x80015910;
s19_weapons_dont_end_turn_800157cc = 0x800157cc;
s_default_80369c14 = 0x80369c14;
s_head_80369c1c = 0x80369c1c;
sol35a8_point_plan_8000831c = 0x8000831c;
sol35a9_point_marker_80008098 = 0x80008098;
sol35a9_point_plan11_v1_8000848c = 0x8000848c;
w3d_center_8041d3a0 = 0x8041d3a0;
w3d_command_create_1 = 0x80007d58;
w3d_command_create_15 = 0x80008ed4;
w3d_command_create_17 = 0x80009164;
w3d_command_create_19 = 0x80009404;
w3d_command_create_3 = 0x80008728;
w3d_command_create_6 = 0x80008d84;
w3d_command_create_7 = 0x80008c44;
w3d_cx11a_command_finish_80009984 = 0x80009984;
w3d_d17a_command_create_16_80009014 = 0x80009014;
w3d_d17a_command_create_800085fc = 0x800085fc;
w3d_d17a_command_create_8000889c = 0x8000889c;
SECTIONS {
  .text.w3d_d43a_weapon_plan_issue_8000affc 0x8000affc : { *(.text.w3d_d43a_weapon_plan_issue_8000affc) }
  .rodata 0x80369c28 : { *(.rodata) }
  .sdata 0x804aa574 (NOLOAD) : {
    . = 0x0; g_elapsed_804aa574 = .;
    . = 0x18; g_wait_804aa58c = .;
    . = 0x164; w3d_settings_804aa6d8 = .;
    . = 0x1dc; w3d_bodies_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
