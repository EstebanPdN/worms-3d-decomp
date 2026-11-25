/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40f_follower_update_80284f84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802e79e0 = 0x802e79e0;
fn_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.w3d_d40f_follower_update_80284f84 0x80284f84 : { *(.text.w3d_d40f_follower_update_80284f84) }
  .rodata 0x803cf360 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
