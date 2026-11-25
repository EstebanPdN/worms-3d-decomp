/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_particle_jitter_toward_800dff7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
half_80389cfc = 0x80389cfc;
rand_80162bc8 = 0x80162bc8;
SECTIONS {
  .text.d27c_particle_jitter_toward_800dff7c 0x800dff7c : { *(.text.d27c_particle_jitter_toward_800dff7c) }
  .rodata 0x80389d00 : { *(.rodata) }
  .sdata 0x804aecb4 (NOLOAD) : {
    . = 0x0; rng_804aecb4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
