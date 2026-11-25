/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d43k_game_state_reset_802487c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020bb2c = 0x8020bb2c;
lbl_804b06a0 = 0x804b06a0;
SECTIONS {
  .text.w3d_d43k_game_state_reset_802487c4 0x802487c4 : { *(.text.w3d_d43k_game_state_reset_802487c4) }
  .rodata 0x803c41d4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
