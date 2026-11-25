/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28b_aim_track_80098388)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
atan2_802e7e5c = 0x802e7e5c;
lbl_8045e788 = 0x8045e788;
sqrt_802e82c0 = 0x802e82c0;
w3d_construct_801f7538 = 0x801f7538;
w3d_member_8003e304 = 0x8003e304;
w3d_sweep_800b0824 = 0x800b0824;
w3d_value_80178c48 = 0x80178c48;
w3d_worm_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.w3d_d28b_aim_track_80098388 0x80098388 : { *(.text.w3d_d28b_aim_track_80098388) }
  .rodata 0x8037f75c : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; lbl_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
