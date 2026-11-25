/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_update_overlay_fade_802c1124)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015fd1c = 0x8015fd1c;
fn_80173df0 = 0x80173df0;
lbl_803d84c8 = 0x803d84c8;
lbl_803d84cc = 0x803d84cc;
lbl_803d84d0 = 0x803d84d0;
SECTIONS {
  .text.w3d_update_overlay_fade_802c1124 0x802c1124 : { *(.text.w3d_update_overlay_fade_802c1124) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
