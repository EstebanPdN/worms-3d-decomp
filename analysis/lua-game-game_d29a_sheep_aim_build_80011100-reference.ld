/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29a_sheep_aim_build_80011100)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc23a_planner_requeue_offset_8000b6bc = 0x8000b6bc;
cc27a_planner_set_gravity_8001aa48 = 0x8001aa48;
fn_8001aaf8 = 0x8001aaf8;
g_centre_8041d3a0 = 0x8041d3a0;
g_motion_8041e780 = 0x8041e780;
s_weapon_803697a4 = 0x803697a4;
sqrt_802e82c0 = 0x802e82c0;
w3d_auto_800fc330 = 0x800fc330;
SECTIONS {
  .text.w3d_d29a_sheep_aim_build_80011100 0x80011100 : { *(.text.w3d_d29a_sheep_aim_build_80011100) }
  .rodata 0x8036a318 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
