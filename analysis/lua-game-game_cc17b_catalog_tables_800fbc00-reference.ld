/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17b_catalog_tables_800fbc00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
catalog_803f5e60 = 0x803f5e60;
catalog_803f7a6c = 0x803f7a6c;
catalog_803fcbc0 = 0x803fcbc0;
catalog_803fcc80 = 0x803fcc80;
SECTIONS {
  .text.w3d_cc17b_catalog_tables_800fbc00 0x800fbc00 : { *(.text.w3d_cc17b_catalog_tables_800fbc00) }
  .sdata 0x804aaf58 (NOLOAD) : {
    . = 0x0; arena_804aaf58 = .;
    . = 0x41b0; part_804af108 = .;
    . = 0x41b4; part_804af10c = .;
    . = 0x41b8; part_804af110 = .;
    . = 0x41bc; part_804af114 = .;
    . = 0x41c0; part_804af118 = .;
    . = 0x41c4; part_804af11c = .;
    . = 0x41c8; part_804af120 = .;
    . = 0x41cc; part_804af124 = .;
    . = 0x41d0; part_804af128 = .;
    . = 0x41d4; count_804af12c = .;
    . = 0x41d8; count_804af130 = .;
    . = 0x41dc; count_804af134 = .;
    . = 0x41e0; count_804af138 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
