/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_weapon_plans_main_8000c14c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__8CostBase = 0x80006360;
_vt.10WeaponPlan = 0x8040d7b8;
_vt.7Weapon0 = 0x8040d5e8;
_vt.7Weapon1 = 0x8040d4e8;
_vt.7Weapon2 = 0x8040d4a8;
_vt.7Weapon5 = 0x8040d3e8;
_vt.7Weapon6 = 0x8040d468;
_vt.8Weapon14 = 0x8040d368;
_vt.8Weapon15 = 0x8040d5a8;
_vt.8Weapon16 = 0x8040d328;
_vt.8Weapon20 = 0x8040d568;
_vt.8Weapon21 = 0x8040d528;
_vt.8Weapon34 = 0x8040d428;
k5a_body_predict_position_800196dc = 0x800196dc;
w3d_ai_push_plan_b = 0x80007514;
w3d_ai_weapon_available = 0x80007ccc;
w3d_auto_8001523c = 0x8001523c;
SECTIONS {
  .text.w3d_d28a_weapon_plans_main_8000c14c 0x8000c14c : { *(.text.w3d_d28a_weapon_plans_main_8000c14c) }
  .rodata 0x80369ccc : { *(.rodata) }
  .sdata 0x804aa594 (NOLOAD) : {
    . = 0x0; w3d_flag_804aa594 = .;
    . = 0x144; w3d_settings_804aa6d8 = .;
    . = 0x1bc; w3d_bodies_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
