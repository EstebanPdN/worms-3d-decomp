/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40z_strtod_802ee800)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
isdigit = 0x802f31d0;
isspace = 0x802f31e4;
powers_of_10_80404ae4 = 0x80404ae4;
w3d_heap_errno_802eafc4 = 0x802eafc4;
SECTIONS {
  .text.w3d_d40z_strtod_802ee800 0x802ee800 : { *(.text.w3d_d40z_strtod_802ee800) }
  .rodata 0x803db628 : { *(.rodata) }
  .sdata 0x804ac57c (NOLOAD) : {
    . = 0x0; w3d_sda_max_exponent_804ac57c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
