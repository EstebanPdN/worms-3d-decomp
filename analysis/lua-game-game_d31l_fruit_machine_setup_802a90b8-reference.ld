/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31l_fruit_machine_setup_802a90b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3StrPCc = 0x8020bb54;
fn_800fc1b0 = 0x800fc1b0;
fn_800fd62c = 0x800fd62c;
fn_8015adf4 = 0x8015adf4;
fn_80165254 = 0x80165254;
fn_80181640 = 0x80181640;
fn_8020bd38 = 0x8020bd38;
fn_8020c510 = 0x8020c510;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_802aa3ec = 0x802aa3ec;
fn_802aa498 = 0x802aa498;
fn_802aa544 = 0x802aa544;
fn_802aa5f0 = 0x802aa5f0;
fn_802aaf5c = 0x802aaf5c;
fn_802ab378 = 0x802ab378;
fn_802b0b84 = 0x802b0b84;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_80343584 = 0x80343584;
str_803d6654 = 0x803d6654;
str_803d6678 = 0x803d6678;
str_803d6688 = 0x803d6688;
str_803d6698 = 0x803d6698;
str_803d669c = 0x803d669c;
str_803d66a0 = 0x803d66a0;
str_803d66a4 = 0x803d66a4;
str_803d66b4 = 0x803d66b4;
str_803d66c4 = 0x803d66c4;
str_803d66d4 = 0x803d66d4;
str_803d66e4 = 0x803d66e4;
str_803d66f4 = 0x803d66f4;
str_803d6704 = 0x803d6704;
str_803d6714 = 0x803d6714;
str_803d6720 = 0x803d6720;
str_803d6730 = 0x803d6730;
str_803d6740 = 0x803d6740;
str_803d6750 = 0x803d6750;
str_803d6760 = 0x803d6760;
str_803d6774 = 0x803d6774;
str_803d6784 = 0x803d6784;
str_803d6794 = 0x803d6794;
str_803d67a4 = 0x803d67a4;
str_803d67b0 = 0x803d67b0;
str_803d67c0 = 0x803d67c0;
str_803d67d0 = 0x803d67d0;
str_803d67e0 = 0x803d67e0;
str_803d67f0 = 0x803d67f0;
str_803d6800 = 0x803d6800;
str_803d6810 = 0x803d6810;
str_803d6820 = 0x803d6820;
str_803d682c = 0x803d682c;
str_803d6840 = 0x803d6840;
str_803d6850 = 0x803d6850;
str_803d6860 = 0x803d6860;
str_803d6870 = 0x803d6870;
str_803d687c = 0x803d687c;
str_803d688c = 0x803d688c;
str_803d689c = 0x803d689c;
str_803d68ac = 0x803d68ac;
str_803d68c0 = 0x803d68c0;
str_803d68d4 = 0x803d68d4;
str_803d68e0 = 0x803d68e0;
table_8045e788 = 0x8045e788;
SECTIONS {
  .text.d31l_fruit_machine_setup_802a90b8 0x802a90b8 : { *(.text.d31l_fruit_machine_setup_802a90b8) }
  .rodata 0x803d68f0 : { *(.rodata) }
  .sdata 0x804abb63 (NOLOAD) : {
    . = 0x0; font_804abb63 = .;
    . = 0x5c25; scene_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
