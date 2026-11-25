/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11a_random_vector_800dd648)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
center_80389b04 = 0x80389b04;
half_80389b0c = 0x80389b0c;
multiplier_80389b00 = 0x80389b00;
random_80162bc8 = 0x80162bc8;
turn_80389b08 = 0x80389b08;
SECTIONS {
  .text.w3d_cx11a_random_vector_800dd648 0x800dd648 : { *(.text.w3d_cx11a_random_vector_800dd648) }
  .rodata 0x80389af8 : { *(.rodata) }
  .sdata 0x804aec54 (NOLOAD) : {
    . = 0x0; seed_804aec54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
