/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11a_count_pool_800dd828)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
center_80389b28 = 0x80389b28;
random_80162bc8 = 0x80162bc8;
SECTIONS {
  .text.w3d_cx11a_count_pool_800dd828 0x800dd828 : { *(.text.w3d_cx11a_count_pool_800dd828) }
  .rodata 0x80389b10 : { *(.rodata) }
  .sdata 0x804aec54 (NOLOAD) : {
    . = 0x0; seed_804aec54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
