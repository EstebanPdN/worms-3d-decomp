/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26l_setup_selection_sprites_802b49b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__13Text_803426b8 = 0x803426b8;
fn_8020bd38 = 0x8020bd38;
fn_8020c510 = 0x8020c510;
fn_8020c5c4 = 0x8020c5c4;
fn_802b1510__4BasePCcPP5IfaceUc = 0x802b1510;
fn_802b4e10 = 0x802b4e10;
fn_80341588 = 0x80341588;
txt_803d7d60 = 0x803d7d60;
txt_803d7e1c = 0x803d7e1c;
txt_803d7e28 = 0x803d7e28;
txt_803d7e30 = 0x803d7e30;
txt_803d7e38 = 0x803d7e38;
txt_803d7e40 = 0x803d7e40;
txt_803d7e48 = 0x803d7e48;
txt_803d7e4c = 0x803d7e4c;
SECTIONS {
  .text.d26l_setup_selection_sprites_802b49b0 0x802b49b0 : { *(.text.d26l_setup_selection_sprites_802b49b0) }
  .rodata 0x803d7e7c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
