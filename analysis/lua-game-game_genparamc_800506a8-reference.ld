/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_show_placeholder_800506a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__18W3dString_803426b8 = 0x803426b8;
fn_8020c5c4 = 0x8020c5c4;
fn_802cbdf8 = 0x802cbdf8;
fn_802cbf2c = 0x802cbf2c;
fn_802cd128 = 0x802cd128;
fn_802cd220 = 0x802cd220;
fn_80341588 = 0x80341588;
lbl_80377f70 = 0x80377f70;
lbl_8037ff74 = 0x8037ff74;
SECTIONS {
  .text.w3d_show_placeholder_800506a8 0x800506a8 : { *(.text.w3d_show_placeholder_800506a8) }
  .text.w3d_show_placeholder_80050730 0x80050730 : { *(.text.w3d_show_placeholder_80050730) }
  .text.w3d_show_placeholder_80099a20 0x80099a20 : { *(.text.w3d_show_placeholder_80099a20) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
