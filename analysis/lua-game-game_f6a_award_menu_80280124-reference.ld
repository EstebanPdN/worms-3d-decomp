/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f6a_award_menu_80280124)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__14Cache_8015f704PCc = 0x8015f704;
addchallenge_803ceca8 = 0x803ceca8;
awarded_803cec70 = 0x803cec70;
campaign_803cec80 = 0x803cec80;
challenge_803cec94 = 0x803cec94;
empty_803ceb40 = 0x803ceb40;
fn_800fc43c = 0x800fc43c;
fn_8010a8e0 = 0x8010a8e0;
fn_8015f558 = 0x8015f558;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
mission_803ce9a0 = 0x803ce9a0;
populate_803ceac8 = 0x803ceac8;
tutorial_803cecbc = 0x803cecbc;
SECTIONS {
  .text.w3d_f6a_award_menu_80280124 0x80280124 : { *(.text.w3d_f6a_award_menu_80280124) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
