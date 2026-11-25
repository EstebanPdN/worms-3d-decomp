/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11a_random_vector_800dd158)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
center_80389aac = 0x80389aac;
multiplier_80389aa8 = 0x80389aa8;
neutral_80389ab0 = 0x80389ab0;
random_80162bc8 = 0x80162bc8;
SECTIONS {
  .text.w3d_cx11a_random_vector_800dd158 0x800dd158 : { *(.text.w3d_cx11a_random_vector_800dd158) }
  .rodata 0x80389aa0 : { *(.rodata) }
  .sdata 0x804aec54 (NOLOAD) : {
    . = 0x0; seed_804aec54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
