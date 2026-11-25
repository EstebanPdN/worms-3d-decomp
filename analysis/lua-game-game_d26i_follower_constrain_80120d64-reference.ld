/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26i_follower_constrain_80120d64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sqrt_802e82c0 = 0x802e82c0;
w3d_a_801211a0 = 0x801211a0;
w3d_b_801212d4 = 0x801212d4;
w3d_cfg_801797b4 = 0x801797b4;
w3d_pull_8012100c = 0x8012100c;
w3d_ref_80341584 = 0x80341584;
SECTIONS {
  .text.d26i_follower_constrain_80120d64 0x80120d64 : { *(.text.d26i_follower_constrain_80120d64) }
  .rodata 0x8039b6e4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
