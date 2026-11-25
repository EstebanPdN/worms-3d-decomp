/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_plan_clone_pair_8000a2d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__8CostBase = 0x80006360;
_vt.10WeaponPlan = 0x8040d7b8;
_vt.5PlanA = 0x8040d6a0;
_vt.5PlanB = 0x8040cce8;
w3d_ai_push_plan_b = 0x80007514;
w3d_auto_8001523c = 0x8001523c;
SECTIONS {
  .text.w3d_d28a_plan_clone_pair_8000a2d0 0x8000a2d0 : { *(.text.w3d_d28a_plan_clone_pair_8000a2d0) }
  .rodata 0x80369bb0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
