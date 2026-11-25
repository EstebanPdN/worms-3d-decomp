/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_worm_pick_aim_8013c5f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
aim_8013b5bc = 0x8013b5bc;
apply_8013c21c = 0x8013c21c;
elevation_8013b898 = 0x8013b898;
index_query_800fc6dc = 0x800fc6dc;
nearest_801263fc = 0x801263fc;
query_801262c0 = 0x801262c0;
targetpos_8003f240 = 0x8003f240;
SECTIONS {
  .text.d25d_worm_pick_aim_8013c5f0 0x8013c5f0 : { *(.text.d25d_worm_pick_aim_8013c5f0) }
  .rodata 0x8039f8f4 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; target_804aa95e = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
