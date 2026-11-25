/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_strike_setup_80021aec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80035714 = 0x80035714;
s8_property_read_800fc5dc = 0x800fc5dc;
s8_property_write_800fc43c = 0x800fc43c;
w3d_f32_8036c158 = 0x8036c158;
w3d_str_8036c0e4 = 0x8036c0e4;
w3d_str_8036c0fc = 0x8036c0fc;
w3d_str_8036c104 = 0x8036c104;
w3d_str_8036c11c = 0x8036c11c;
w3d_str_8036c12c = 0x8036c12c;
w3d_str_8036c140 = 0x8036c140;
SECTIONS {
  .text.k4a_strike_setup_80021aec 0x80021aec : { *(.text.k4a_strike_setup_80021aec) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; w3d_object_804aa8c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
