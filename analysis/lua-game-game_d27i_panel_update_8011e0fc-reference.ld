/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27i_panel_update_8011e0fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
color_80189760 = 0x80189760;
ctx_80165254 = 0x80165254;
msgid_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
ready_80181ccc = 0x80181ccc;
svc_8020b680 = 0x8020b680;
svc_804140d0 = 0x804140d0;
vec_8011f2c8 = 0x8011f2c8;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.d27i_panel_update_8011e0fc 0x8011e0fc : { *(.text.d27i_panel_update_8011e0fc) }
  .rodata 0x8039b368 : { *(.rodata) }
  .sdata 0x804af47c (NOLOAD) : {
    . = 0x0; name_804af47c = .;
    . = 0x22d8; arena_804b1754 = .;
    . = 0x230c; game_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
