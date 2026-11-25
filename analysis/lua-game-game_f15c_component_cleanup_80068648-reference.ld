/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f15c_component_cleanup_80068648)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8015ff2c = 0x8015ff2c;
finish_8020c5c4 = 0x8020c5c4;
handle_80126230 = 0x80126230;
release_80341588 = 0x80341588;
vtable_8040ef28 = 0x8040ef28;
SECTIONS {
  .text.f15c_component_cleanup_80068648 0x80068648 : { *(.text.f15c_component_cleanup_80068648) }
  .sdata 0x804aaa9c (NOLOAD) : {
    . = 0x0; selected_804aaa9c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
