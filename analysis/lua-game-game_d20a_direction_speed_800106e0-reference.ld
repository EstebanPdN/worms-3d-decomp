/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d20a_direction_speed_800106e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_directed_apply_8000feb8 = 0x8000feb8;
w3d_directed_ready_8000f804 = 0x8000f804;
w3d_directed_tuning_80341694 = 0x80341694;
w3d_sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.w3d_d20a_direction_speed_800106e0 0x800106e0 : { *(.text.w3d_d20a_direction_speed_800106e0) }
  .rodata 0x8036a178 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
