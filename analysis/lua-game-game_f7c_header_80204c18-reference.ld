/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f7c_header_80204c18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802047ac = 0x802047ac;
fn_802eefe0 = 0x802eefe0;
SECTIONS {
  .text.f7c_header_80204c18 0x80204c18 : { *(.text.f7c_header_80204c18) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
