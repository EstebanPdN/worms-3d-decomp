/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25c_actor_align_rotation_800ed440)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acosf_802e79e0 = 0x802e79e0;
set_axis_angle_801f656c = 0x801f656c;
sqrtf_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d25c_actor_align_rotation_800ed440 0x800ed440 : { *(.text.d25c_actor_align_rotation_800ed440) }
  .rodata 0x8038b608 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
