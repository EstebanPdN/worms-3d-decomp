/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_panel_mesh_reset_802b1cec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cast_80343584 = 0x80343584;
check_8018179c = 0x8018179c;
control_801817e0 = 0x801817e0;
reset_80181640 = 0x80181640;
reset_803d7ac0 = 0x803d7ac0;
start_803d7ac8 = 0x803d7ac8;
zero_803d7acc = 0x803d7acc;
SECTIONS {
  .text.w3d_cx12b_panel_mesh_reset_802b1cec 0x802b1cec : { *(.text.w3d_cx12b_panel_mesh_reset_802b1cec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
