/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc42a_remove_unused_80178578)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc42a_find_80177eb0 = 0x80177eb0;
cc42a_refresh_801787ec = 0x801787ec;
SECTIONS {
  .text.cc42a_remove_unused_80178578 0x80178578 : { *(.text.cc42a_remove_unused_80178578) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
