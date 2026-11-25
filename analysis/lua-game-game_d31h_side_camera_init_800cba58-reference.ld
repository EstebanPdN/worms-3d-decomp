/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31h_side_camera_init_800cba58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
alloc_801613f0 = 0x801613f0;
base_8015a6b8 = 0x8015a6b8;
construct_801f7538 = 0x801f7538;
in_range_800cc070 = 0x800cc070;
lbl_8040db38 = 0x8040db38;
message_id_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
query_800fc6dc = 0x800fc6dc;
read_80178c48 = 0x80178c48;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d31h_side_camera_init_800cba58 0x800cba58 : { *(.text.d31h_side_camera_init_800cba58) }
  .rodata 0x80387d10 : { *(.rodata) }
  .sdata 0x804ae838 (NOLOAD) : {
    . = 0x0; lbl_804ae838 = .;
    . = 0x2f1c; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
