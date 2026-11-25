/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27i_particle_ring_update_8012aab0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
col_80189760 = 0x80189760;
pos_80189518 = 0x80189518;
rnd_8015ff5c = 0x8015ff5c;
rot_80189574 = 0x80189574;
size_8018963c = 0x8018963c;
SECTIONS {
  .text.d27i_particle_ring_update_8012aab0 0x8012aab0 : { *(.text.d27i_particle_ring_update_8012aab0) }
  .rodata 0x8039d278 : { *(.rodata) }
  .sdata 0x804b183c (NOLOAD) : {
    . = 0x0; source_804b183c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
