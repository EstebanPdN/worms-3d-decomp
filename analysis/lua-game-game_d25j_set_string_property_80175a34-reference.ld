/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25j_set_string_property_80175a34)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80177eb0 = 0x80177eb0;
fn_80179038 = 0x80179038;
fn_801790bc = 0x801790bc;
fn_801fe1d8 = 0x801fe1d8;
fn_80343744 = 0x80343744;
SECTIONS {
  .text.d25j_set_string_property_80175a34 0x80175a34 : { *(.text.d25j_set_string_property_80175a34) }
  .sdata 0x804ab5b0 (NOLOAD) : {
    . = 0x0; var_804ab5b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
