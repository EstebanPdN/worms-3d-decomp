/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_constructor_lookup_name)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_constructor_lookup_name 0x800fc1b0 : { *(.text.w3d_constructor_lookup_name) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_constructor_lookup_context = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
