/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40d_worm_graphic_update_80133d74)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
alloc_801613f0 = 0x801613f0;
anim_80135c20 = 0x80135c20;
colour_80139b3c = 0x80139b3c;
construct_801f7538 = 0x801f7538;
delta_8013aa10 = 0x8013aa10;
far_8039f1ec = 0x8039f1ec;
forward_8013dda8 = 0x8013dda8;
index_query_800fc6dc = 0x800fc6dc;
isCurrent_80139158 = 0x80139158;
msg_id_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
pot_8013586c = 0x8013586c;
refresh_8013f2f8 = 0x8013f2f8;
set_tint_80182178 = 0x80182178;
sqrt_802e82c0 = 0x802e82c0;
tail_8013f73c = 0x8013f73c;
test_800b0824 = 0x800b0824;
vec_message_80126000 = 0x80126000;
SECTIONS {
  .text.w3d_d40d_worm_graphic_update_80133d74 0x80133d74 : { *(.text.w3d_d40d_worm_graphic_update_80133d74) }
  .rodata 0x8039f1f0 : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; scene_804aa8c8 = .;
    . = 0x4f28; cache_804af7f0 = .;
    . = 0x6e8c; heap_804b1754 = .;
    . = 0x6e9c; traceFrac_804b1764 = .;
    . = 0x6ec0; system_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
