/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(e14b_publish_8016a4f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
e14b_dispatch_8030ba64 = 0x8030ba64;
SECTIONS {
  .text.e14b_publish_8016a4f4 0x8016a4f4 : { *(.text.e14b_publish_8016a4f4) }
  .sdata 0x804ab51c (NOLOAD) : {
    . = 0x0; e14b_table_804ab51c = .;
    . = 0x4; e14b_flag_804ab520 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
