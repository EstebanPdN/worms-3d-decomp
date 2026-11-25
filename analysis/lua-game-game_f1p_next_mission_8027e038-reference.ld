/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_next_mission_8027e038)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__14Cache_8015f704PCc = 0x8015f704;
campaigntext_803ceadc = 0x803ceadc;
current_803ceab4 = 0x803ceab4;
fn_800fc230 = 0x800fc230;
fn_800fc43c = 0x800fc43c;
fn_8010a8e0 = 0x8010a8e0;
fn_8015f558 = 0x8015f558;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_8020c5c4 = 0x8020c5c4;
fn_8027be7c = 0x8027be7c;
fn_8027d2ac = 0x8027d2ac;
fn_80341588 = 0x80341588;
mission_803ce9a0 = 0x803ce9a0;
next_803ceb44 = 0x803ceb44;
populate_803ceac8 = 0x803ceac8;
retry_803cea38 = 0x803cea38;
tutorialtext_803cecd0 = 0x803cecd0;
SECTIONS {
  .text.w3d_next_mission_8027e038 0x8027e038 : { *(.text.w3d_next_mission_8027e038) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
