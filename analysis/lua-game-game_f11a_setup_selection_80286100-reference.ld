/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f11a_setup_selection_80286100)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__26F11aSelectionText_803426b8 = 0x803426b8;
fn_8020bd38 = 0x8020bd38;
fn_8020c510 = 0x8020c510;
fn_8020c5c4 = 0x8020c5c4;
fn_802870fc = 0x802870fc;
fn_802b1510__8F11aBasePCcPP9F11aIfaceUc = 0x802b1510;
fn_80341588 = 0x80341588;
txt_803cf40c = 0x803cf40c;
txt_803cf418 = 0x803cf418;
txt_803cf43c = 0x803cf43c;
txt_803cf444 = 0x803cf444;
txt_803cf44c = 0x803cf44c;
txt_803cf454 = 0x803cf454;
txt_803cf45c = 0x803cf45c;
txt_803cf460 = 0x803cf460;
SECTIONS {
  .text.w3d_f11a_setup_selection_80286100 0x80286100 : { *(.text.w3d_f11a_setup_selection_80286100) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
