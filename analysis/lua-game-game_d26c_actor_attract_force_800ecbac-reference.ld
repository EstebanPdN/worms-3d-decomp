/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_actor_attract_force_800ecbac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
limit_800668dc = 0x800668dc;
rate_800668fc = 0x800668fc;
sqrt_802e82c0 = 0x802e82c0;
velocity_800668b8 = 0x800668b8;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d26c_actor_attract_force_800ecbac 0x800ecbac : { *(.text.d26c_actor_attract_force_800ecbac) }
  .rodata 0x8038b5a8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
