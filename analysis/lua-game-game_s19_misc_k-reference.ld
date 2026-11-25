/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_unit_step_8000d568)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8000b2f8 = 0x8000b2f8;
w3d_cached_name_lookup_80341710 = 0x80341710;
SECTIONS {
  .text.s19_unit_step_8000d568 0x8000d568 : { *(.text.s19_unit_step_8000d568) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; lbl_804aa6d8 = .;
    . = 0x78; lbl_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
