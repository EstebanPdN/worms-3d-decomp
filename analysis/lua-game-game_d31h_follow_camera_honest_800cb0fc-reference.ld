/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31h_follow_camera_honest_800cb0fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
construct_801f7538 = 0x801f7538;
in_range_800cc070 = 0x800cc070;
orbit_800cc148 = 0x800cc148;
query_800fc6dc = 0x800fc6dc;
read_80178c48 = 0x80178c48;
SECTIONS {
  .text.d31h_follow_camera_honest_800cb0fc 0x800cb0fc : { *(.text.d31h_follow_camera_honest_800cb0fc) }
  .rodata 0x80387ce4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
