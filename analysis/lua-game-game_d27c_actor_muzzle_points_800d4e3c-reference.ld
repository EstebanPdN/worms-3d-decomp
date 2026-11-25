/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_actor_muzzle_points_800d4e3c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cos_802e86d4 = 0x802e86d4;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
euler_801a3eb0 = 0x801a3eb0;
sin_802e88ac = 0x802e88ac;
SECTIONS {
  .text.d27c_actor_muzzle_points_800d4e3c 0x800d4e3c : { *(.text.d27c_actor_muzzle_points_800d4e3c) }
  .rodata 0x80388d48 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
