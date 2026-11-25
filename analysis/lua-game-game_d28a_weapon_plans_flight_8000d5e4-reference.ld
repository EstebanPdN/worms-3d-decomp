/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_weapon_plans_flight_8000d5e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__8CostBase = 0x80006360;
_vt.10WeaponPlan = 0x8040d7b8;
_vt.7Weapon8 = 0x8040d268;
_vt.7Weapon9 = 0x8040d2a8;
_vt.8Weapon30 = 0x8040d228;
w3d_ai_push_plan_b = 0x80007514;
w3d_ai_weapon_available = 0x80007ccc;
w3d_auto_8001523c = 0x8001523c;
w3d_auto_80015794 = 0x80015794;
SECTIONS {
  .text.w3d_d28a_weapon_plans_flight_8000d5e4 0x8000d5e4 : { *(.text.w3d_d28a_weapon_plans_flight_8000d5e4) }
  .rodata 0x80369e7c : { *(.rodata) }
  .sdata 0x804aa594 (NOLOAD) : {
    . = 0x0; w3d_flag_804aa594 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
