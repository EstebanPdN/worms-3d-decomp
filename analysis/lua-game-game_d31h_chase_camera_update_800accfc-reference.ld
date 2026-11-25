/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31h_chase_camera_update_800accfc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
construct_801f7538 = 0x801f7538;
query_800fc6dc = 0x800fc6dc;
read_80178c48 = 0x80178c48;
sqrt_802e82c0 = 0x802e82c0;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.d31h_chase_camera_update_800accfc 0x800accfc : { *(.text.d31h_chase_camera_update_800accfc) }
  .rodata 0x80381ff4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
