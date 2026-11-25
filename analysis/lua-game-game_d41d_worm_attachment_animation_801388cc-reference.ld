/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41d_worm_attachment_animation_801388cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cls_80368468 = 0x80368468;
lbl_803eb63c = 0x803eb63c;
s8_index_query_800fc6dc = 0x800fc6dc;
w3d_auto_800fc330 = 0x800fc330;
w3d_auto_8013f08c = 0x8013f08c;
w3d_s20_forward_global5_800e5cf0 = 0x800e5cf0;
w3d_worm_play_801359ec = 0x801359ec;
SECTIONS {
  .text.w3d_d41d_worm_attachment_animation_801388cc 0x801388cc : { *(.text.w3d_d41d_worm_attachment_animation_801388cc) }
  .rodata 0x8039f5b0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
