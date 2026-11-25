/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31x_rope_trail_update_800cd178)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
angles_800ccf50 = 0x800ccf50;
attached_800cfc80 = 0x800cfc80;
count_800d0f54 = 0x800d0f54;
detach_800cd990 = 0x800cd990;
lbl_80387df8 = 0x80387df8;
lbl_80387e28 = 0x80387e28;
lbl_8045e788 = 0x8045e788;
lookup_80164fc8 = 0x80164fc8;
mode2_800cfc98 = 0x800cfc98;
pending_800ccd54 = 0x800ccd54;
point_800d0f74 = 0x800d0f74;
read_800fc1f0 = 0x800fc1f0;
resize_800ccdd8 = 0x800ccdd8;
spawn_800ccc14 = 0x800ccc14;
sqrt_802e82c0 = 0x802e82c0;
trail_update_800cd834 = 0x800cd834;
worm_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.d31x_rope_trail_update_800cd178 0x800cd178 : { *(.text.d31x_rope_trail_update_800cd178) }
  .rodata 0x80387e38 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
