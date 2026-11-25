/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_weapon_plans_refine_8000dd7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__8CostBase = 0x80006360;
_vt.10WeaponPlan = 0x8040d7b8;
_vt.7Bazooka = 0x8040d1b8;
_vt.7Grenade = 0x8040d110;
k5a_body_predict_position_800196dc = 0x800196dc;
w3d_ai_push_plan_b = 0x80007514;
w3d_ai_weapon_available = 0x80007ccc;
w3d_auto_8001523c = 0x8001523c;
SECTIONS {
  .text.w3d_d28a_weapon_plans_refine_8000dd7c 0x8000dd7c : { *(.text.w3d_d28a_weapon_plans_refine_8000dd7c) }
  .rodata 0x80369f1c : { *(.rodata) }
  .sdata 0x804aa594 (NOLOAD) : {
    . = 0x0; w3d_flag_804aa594 = .;
    . = 0x1bc; w3d_bodies_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
