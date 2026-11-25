/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f15c_component_initialize_80068570)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__14F15cCtorString = 0x803426b8;
base_8015fef0 = 0x8015fef0;
vtable_8040ef28 = 0x8040ef28;
SECTIONS {
  .text.f15c_component_initialize_80068570 0x80068570 : { *(.text.f15c_component_initialize_80068570) }
  .sdata 0x804aaa9c (NOLOAD) : {
    . = 0x0; selected_804aaa9c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
