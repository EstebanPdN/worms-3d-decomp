/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx13a_initialize_screen_800c8574)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8015fef0 = 0x8015fef0;
initial_80387af4 = 0x80387af4;
vtable_8040fb38 = 0x8040fb38;
SECTIONS {
  .text.w3d_cx13a_initialize_screen_800c8574 0x800c8574 : { *(.text.w3d_cx13a_initialize_screen_800c8574) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
