/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_actor_steer_angle_800dbda8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
acos_802e79e0 = 0x802e79e0;
construct_801f7538 = 0x801f7538;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d27c_actor_steer_angle_800dbda8 0x800dbda8 : { *(.text.d27c_actor_steer_angle_800dbda8) }
  .rodata 0x803898a4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
