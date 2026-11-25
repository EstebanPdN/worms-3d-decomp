/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27i_input_state_ctor_8012c098)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_80161014 = 0x80161014;
table_80451a9c = 0x80451a9c;
vt_80410e00 = 0x80410e00;
SECTIONS {
  .text.d27i_input_state_ctor_8012c098 0x8012c098 : { *(.text.d27i_input_state_ctor_8012c098) }
  .sdata 0x804ab0cc (NOLOAD) : {
    . = 0x0; current_804ab0cc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
