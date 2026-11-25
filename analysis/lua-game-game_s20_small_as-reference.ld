/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_lookup_vector_80176aac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80177eb0 = 0x80177eb0;
fn_80178ec4 = 0x80178ec4;
fn_80342fa4 = 0x80342fa4;
SECTIONS {
  .text.w3d_s20_lookup_vector_80176aac 0x80176aac : { *(.text.w3d_s20_lookup_vector_80176aac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
