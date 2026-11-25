/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11a_random_vector_800dd424)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
center_80389ae4 = 0x80389ae4;
half_80389aec = 0x80389aec;
multiplier_80389ae0 = 0x80389ae0;
neutral_80389af0 = 0x80389af0;
random_80162bc8 = 0x80162bc8;
turn_80389ae8 = 0x80389ae8;
SECTIONS {
  .text.w3d_cx11a_random_vector_800dd424 0x800dd424 : { *(.text.w3d_cx11a_random_vector_800dd424) }
  .rodata 0x80389ad8 : { *(.rodata) }
  .sdata 0x804aec54 (NOLOAD) : {
    . = 0x0; seed_804aec54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
