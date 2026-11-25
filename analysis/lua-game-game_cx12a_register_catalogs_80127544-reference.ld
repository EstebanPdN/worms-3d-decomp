/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12a_register_catalogs_80127544)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
table_803f5e60 = 0x803f5e60;
table_803f7a6c = 0x803f7a6c;
table_803fcbc0 = 0x803fcbc0;
table_803fcc80 = 0x803fcc80;
table_804021e8 = 0x804021e8;
table_804024a4 = 0x804024a4;
table_80403980 = 0x80403980;
table_804039b0 = 0x804039b0;
table_804abc28 = 0x804abc28;
SECTIONS {
  .text.w3d_cx12a_register_catalogs_80127544 0x80127544 : { *(.text.w3d_cx12a_register_catalogs_80127544) }
  .sdata 0x804af12c (NOLOAD) : {
    . = 0x0; count_804af12c = .;
    . = 0x4; count_804af130 = .;
    . = 0x8; count_804af134 = .;
    . = 0xc; count_804af138 = .;
    . = 0x1d88; count_804b0eb4 = .;
    . = 0x1d8c; count_804b0eb8 = .;
    . = 0x1d90; count_804b0ebc = .;
    . = 0x1d94; count_804b0ec0 = .;
    . = 0x1d98; count_804b0ec4 = .;
    . = 0x26c0; service_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
