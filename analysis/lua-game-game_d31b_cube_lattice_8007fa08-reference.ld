/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31b_cube_lattice_8007fa08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_h1_8037cf4c = 0x8037cf4c;
w3d_h2_8037cfac = 0x8037cfac;
w3d_h4_8037d06c = 0x8037d06c;
w3d_vert_80431460 = 0x80431460;
SECTIONS {
  .text.w3d_d31b_cube_lattice_8007fa08 0x8007fa08 : { *(.text.w3d_d31b_cube_lattice_8007fa08) }
  .rodata 0x8037cf24 : { *(.rodata) }
  .sdata 0x804ada6c (NOLOAD) : {
    . = 0x0; w3d_level_804ada6c = .;
    . = 0x1; w3d_level_804ada6d = .;
    . = 0x2; w3d_level_804ada6e = .;
    . = 0x3; w3d_level_804ada6f = .;
    . = 0x4; w3d_level_804ada70 = .;
    . = 0x5; w3d_level_804ada71 = .;
    . = 0x6; w3d_level_804ada72 = .;
    . = 0x7; w3d_level_804ada73 = .;
    . = 0x8; w3d_col_804ada74 = .;
    . = 0xc; w3d_col_804ada78 = .;
    . = 0x10; w3d_col_804ada7c = .;
    . = 0x14; w3d_col_804ada80 = .;
    . = 0x18; w3d_col_804ada84 = .;
    . = 0x1c; w3d_col_804ada88 = .;
    . = 0x20; w3d_col_804ada8c = .;
    . = 0x24; w3d_col_804ada90 = .;
    . = 0x28; w3d_col_804ada94 = .;
    . = 0x2c; w3d_col_804ada98 = .;
    . = 0x30; w3d_col_804ada9c = .;
    . = 0x34; w3d_col_804adaa0 = .;
    . = 0x38; w3d_col_804adaa4 = .;
    . = 0x3c; w3d_col_804adaa8 = .;
    . = 0x40; w3d_col_804adaac = .;
    . = 0x44; w3d_col_804adab0 = .;
    . = 0x88; w3d_edge_804adaf4 = .;
    . = 0x8c; w3d_edge_804adaf8 = .;
    . = 0x90; w3d_edge_804adafc = .;
    . = 0x94; w3d_edge_804adb00 = .;
    . = 0x98; w3d_edge_804adb04 = .;
    . = 0x9c; w3d_edge_804adb08 = .;
    . = 0xa0; w3d_edge_804adb0c = .;
    . = 0xa4; w3d_edge_804adb10 = .;
    . = 0xb4; w3d_flags_a_804adb20 = .;
    . = 0xb8; w3d_flags_b_804adb24 = .;
    . = 0xbc; w3d_centre_col_804adb28 = .;
    . = 0xc4; w3d_centre_col_804adb30 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
