/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_weapon_plans_retreat_8000ebe4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__8CostBase = 0x80006360;
_vt.10WeaponPlan = 0x8040d7b8;
_vt.7Weapon1 = 0x8040cee0;
_vt.7Weapon2 = 0x8040cea8;
_vt.7Weapon4 = 0x8040cf88;
_vt.7Weapon6 = 0x8040ce70;
_vt.7Weapon7 = 0x8040cf50;
_vt.8Weapon10 = 0x8040d0a0;
_vt.8Weapon11 = 0x8040d068;
_vt.8Weapon12 = 0x8040d030;
_vt.8Weapon13 = 0x8040cff8;
_vt.8Weapon33 = 0x8040ce38;
k5a_body_predict_position_800196dc = 0x800196dc;
w3d_ai_push_plan_b = 0x80007514;
w3d_ai_weapon_available = 0x80007ccc;
w3d_auto_8001523c = 0x8001523c;
w3d_auto_800fc1f0 = 0x800fc1f0;
SECTIONS {
  .text.w3d_d28a_weapon_plans_retreat_8000ebe4 0x8000ebe4 : { *(.text.w3d_d28a_weapon_plans_retreat_8000ebe4) }
  .rodata 0x8036a058 : { *(.rodata) }
  .sdata 0x804aa594 (NOLOAD) : {
    . = 0x0; w3d_flag_804aa594 = .;
    . = 0x148; w3d_game_804aa6dc = .;
    . = 0x14c; w3d_busy_804aa6e0 = .;
    . = 0x1bc; w3d_bodies_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
