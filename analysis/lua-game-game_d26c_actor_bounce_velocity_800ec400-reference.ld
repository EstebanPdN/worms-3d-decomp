/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_actor_bounce_velocity_800ec400)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
key_8038b470 = 0x8038b470;
read_800fc270 = 0x800fc270;
respond_800c2494 = 0x800c2494;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d26c_actor_bounce_velocity_800ec400 0x800ec400 : { *(.text.d26c_actor_bounce_velocity_800ec400) }
  .rodata 0x8038b558 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
