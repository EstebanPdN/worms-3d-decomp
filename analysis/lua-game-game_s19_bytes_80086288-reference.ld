/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_load_byte_table_80086288)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.s19_load_byte_table_80086288 0x80086288 : { *(.text.s19_load_byte_table_80086288) }
  .sdata 0x804ada6c (NOLOAD) : {
    . = 0x0; lbl_804ada6c = .;
    . = 0x380; lbl_804addec = .;
    . = 0x384; lbl_804addf0 = .;
    . = 0x388; lbl_804addf4 = .;
    . = 0x38c; lbl_804addf8 = .;
    . = 0x390; lbl_804addfc = .;
    . = 0x394; lbl_804ade00 = .;
    . = 0x398; lbl_804ade04 = .;
    . = 0x39c; lbl_804ade08 = .;
    . = 0x3d94; lbl_804b1800 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
