/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_read_launch_velocity_8002190c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s8_property_read_800fc5dc = 0x800fc5dc;
SECTIONS {
  .text.s19_read_launch_velocity_8002190c 0x8002190c : { *(.text.s19_read_launch_velocity_8002190c) }
  .rodata 0x8036c07c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
