/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d16d_actor_choose_fall_reaction_8014e80c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80153f58 = 0x80153f58;
w3d_auto_801610a0 = 0x801610a0;
w3d_fn_800b0824 = 0x800b0824;
w3d_motion_set_actor_value = 0x801492ec;
w3d_zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d16d_actor_choose_fall_reaction_8014e80c 0x8014e80c : { *(.text.d16d_actor_choose_fall_reaction_8014e80c) }
  .rodata 0x803a1748 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; w3d_cast_result_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
