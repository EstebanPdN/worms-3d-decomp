/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_particle_motion_at_800ddd74)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cos_802e86d4 = 0x802e86d4;
orbit_800e5a70 = 0x800e5a70;
sin_802e88ac = 0x802e88ac;
SECTIONS {
  .text.d27c_particle_motion_at_800ddd74 0x800ddd74 : { *(.text.d27c_particle_motion_at_800ddd74) }
  .rodata 0x80389b78 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
