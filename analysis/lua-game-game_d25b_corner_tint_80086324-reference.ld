/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25b_corner_tint_80086324)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_d25b_corner_tint_80086324 0x80086324 : { *(.text.w3d_d25b_corner_tint_80086324) }
  .sdata 0x804ada74 (NOLOAD) : {
    . = 0x0; w3d_tint_corner_804ada74 = .;
    . = 0x4; w3d_tint_corner_804ada78 = .;
    . = 0x8; w3d_tint_corner_804ada7c = .;
    . = 0xc; w3d_tint_corner_804ada80 = .;
    . = 0x10; w3d_tint_corner_804ada84 = .;
    . = 0x14; w3d_tint_corner_804ada88 = .;
    . = 0x18; w3d_tint_corner_804ada8c = .;
    . = 0x1c; w3d_tint_corner_804ada90 = .;
    . = 0x20; w3d_tint_corner_804ada94 = .;
    . = 0x24; w3d_tint_corner_804ada98 = .;
    . = 0x28; w3d_tint_corner_804ada9c = .;
    . = 0x2c; w3d_tint_corner_804adaa0 = .;
    . = 0x30; w3d_tint_corner_804adaa4 = .;
    . = 0x34; w3d_tint_corner_804adaa8 = .;
    . = 0x38; w3d_tint_corner_804adaac = .;
    . = 0x3c; w3d_tint_corner_804adab0 = .;
    . = 0xb4; w3d_tint_row_804adb28 = .;
    . = 0xbc; w3d_tint_row_804adb30 = .;
    . = 0x378; w3d_tint_offset_804addec = .;
    . = 0x37c; w3d_tint_offset_804addf0 = .;
    . = 0x380; w3d_tint_offset_804addf4 = .;
    . = 0x384; w3d_tint_offset_804addf8 = .;
    . = 0x388; w3d_tint_offset_804addfc = .;
    . = 0x38c; w3d_tint_offset_804ade00 = .;
    . = 0x390; w3d_tint_offset_804ade04 = .;
    . = 0x394; w3d_tint_offset_804ade08 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
