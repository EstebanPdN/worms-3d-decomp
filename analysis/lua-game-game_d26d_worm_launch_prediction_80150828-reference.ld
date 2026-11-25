/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_worm_launch_prediction_80150828)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
cameraData_803a181c = 0x803a181c;
float_prop_800fc270 = 0x800fc270;
msg_id_8015f5a0 = 0x8015f5a0;
play_800356e0 = 0x800356e0;
post_8015fc58 = 0x8015fc58;
prop_int_800fc43c = 0x800fc43c;
prop_string_800fc550 = 0x800fc550;
sound_803a1834 = 0x803a1834;
start_80150b38 = 0x80150b38;
taskKey_803a1810 = 0x803a1810;
test_800b0824 = 0x800b0824;
track_803a1800 = 0x803a1800;
vt_8040db38 = 0x8040db38;
waterKey_803a1000 = 0x803a1000;
water_time_800419cc = 0x800419cc;
zero_803a183c = 0x803a183c;
SECTIONS {
  .text.d26d_worm_launch_prediction_80150828 0x80150828 : { *(.text.d26d_worm_launch_prediction_80150828) }
  .rodata 0x803a1840 : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; sound_804aa8c8 = .;
    . = 0x5420; cache_804afce8 = .;
    . = 0x6e8c; heap_804b1754 = .;
    . = 0x6e9c; traceFrac_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
