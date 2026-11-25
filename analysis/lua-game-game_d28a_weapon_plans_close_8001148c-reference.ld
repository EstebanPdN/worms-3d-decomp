/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_weapon_plans_close_8001148c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__8CostBase = 0x80006360;
_vt.10WeaponPlan = 0x8040d7b8;
_vt.7Weapon2 = 0x8040ccb0;
_vt.8Weapon17 = 0x8040cc40;
_vt.8Weapon26 = 0x8040cc08;
_vt.8Weapon43 = 0x8040cbd0;
w3d_ai_push_plan_b = 0x80007514;
w3d_ai_weapon_available = 0x80007ccc;
w3d_auto_8001523c = 0x8001523c;
SECTIONS {
  .text.w3d_d28a_weapon_plans_close_8001148c 0x8001148c : { *(.text.w3d_d28a_weapon_plans_close_8001148c) }
  .rodata 0x8036a354 : { *(.rodata) }
  .sdata 0x804aa594 (NOLOAD) : {
    . = 0x0; w3d_flag_804aa594 = .;
    . = 0x148; w3d_game_804aa6dc = .;
    . = 0x14c; w3d_busy_804aa6e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
