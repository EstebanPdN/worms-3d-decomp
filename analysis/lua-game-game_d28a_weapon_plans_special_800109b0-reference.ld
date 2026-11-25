/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_weapon_plans_special_800109b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__12MethodMember = 0x801181bc;
__8CostBase = 0x80006360;
_vt.10WeaponPlan = 0x8040d7b8;
_vt.8Weapon18 = 0x8040cdc8;
_vt.8Weapon23 = 0x8040cd58;
_vt.8Weapon24 = 0x8040cd90;
_vt.8Weapon29 = 0x8040cd20;
w3d_ai_push_plan_b = 0x80007514;
w3d_ai_weapon_available = 0x80007ccc;
w3d_auto_8001523c = 0x8001523c;
SECTIONS {
  .text.w3d_d28a_weapon_plans_special_800109b0 0x800109b0 : { *(.text.w3d_d28a_weapon_plans_special_800109b0) }
  .rodata 0x8036a28c : { *(.rodata) }
  .sdata 0x804aa594 (NOLOAD) : {
    . = 0x0; w3d_flag_804aa594 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
