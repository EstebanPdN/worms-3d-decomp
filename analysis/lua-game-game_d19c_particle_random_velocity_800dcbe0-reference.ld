/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19c_particle_random_velocity_800dcbe0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d19c_random_unit_80162bc8 = 0x80162bc8;
d19c_sqrtf_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d19c_particle_random_velocity_800dcbe0 0x800dcbe0 : { *(.text.d19c_particle_random_velocity_800dcbe0) }
  .rodata 0x80389a48 : { *(.rodata) }
  .sdata 0x804aec54 (NOLOAD) : {
    . = 0x0; d19c_local_seed_804aec54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
