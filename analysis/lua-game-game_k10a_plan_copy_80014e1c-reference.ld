/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_plan_copy_80014e1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_method_member_initialize = 0x801181bc;
w3d_f32_8036a52c = 0x8036a52c;
w3d_path_cost_construct = 0x80006360;
w3d_vtable_8040cd20 = 0x8040cd20;
w3d_vtable_8040d7b8 = 0x8040d7b8;
SECTIONS {
  .text.w3d_k10a_plan_copy_80014e1c 0x80014e1c : { *(.text.w3d_k10a_plan_copy_80014e1c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
