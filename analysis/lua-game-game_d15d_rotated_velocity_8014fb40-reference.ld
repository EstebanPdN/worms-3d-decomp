/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d15d_actor_apply_rotated_velocity_8014fb40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__8D15dVec3 = 0x80343740;
w3d_auto_80178ec4 = 0x80178ec4;
w3d_f32_803a17b0 = 0x803a17b0;
w3d_f32_803a17b4 = 0x803a17b4;
w3d_motion_set_actor_value = 0x801492ec;
w3d_s21_construct_801f7538 = 0x801f7538;
SECTIONS {
  .text.d15d_actor_apply_rotated_velocity_8014fb40 0x8014fb40 : { *(.text.d15d_actor_apply_rotated_velocity_8014fb40) }
  .sdata 0x804afde8 (NOLOAD) : {
    . = 0x0; w3d_global_804afde8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
