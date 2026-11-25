/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ai_push_area_trajectory_80011d00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_8036a3e0 = 0x8036a3e0;
w3d_f32_8036a410 = 0x8036a410;
w3d_f32_8036a438 = 0x8036a438;
w3d_f32_8036a468 = 0x8036a468;
w3d_fn_8000affc = 0x8000affc;
w3d_fn_8000b6bc = 0x8000b6bc;
w3d_fn_800106e0 = 0x800106e0;
SECTIONS {
  .text.w3d_ai_push_area_trajectory_80011d00 0x80011d00 : { *(.text.w3d_ai_push_area_trajectory_80011d00) }
  .text.w3d_ai_execute_all_actors_80011fd4 0x80011fd4 : { *(.text.w3d_ai_execute_all_actors_80011fd4) }
  .text.w3d_ai_execute_other_teams_800120c8 0x800120c8 : { *(.text.w3d_ai_execute_other_teams_800120c8) }
  .text.w3d_ai_execute_average_damage_80012278 0x80012278 : { *(.text.w3d_ai_execute_average_damage_80012278) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
