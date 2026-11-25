/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_play_sound_pair_800edc28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800356e0 = 0x800356e0;
fn_80035714 = 0x80035714;
fn_800fc43c = 0x800fc43c;
fn_800fc550 = 0x800fc550;
lbl_8038b634 = 0x8038b634;
lbl_8038b640 = 0x8038b640;
lbl_8038b658 = 0x8038b658;
lbl_8038b660 = 0x8038b660;
lbl_8038b664 = 0x8038b664;
lbl_8038b66c = 0x8038b66c;
lbl_8038b670 = 0x8038b670;
lbl_8038b674 = 0x8038b674;
lbl_8038b67c = 0x8038b67c;
SECTIONS {
  .text.w3d_s20_play_sound_pair_800edc28 0x800edc28 : { *(.text.w3d_s20_play_sound_pair_800edc28) }
  .text.w3d_s20_play_sound_pair_800edca0 0x800edca0 : { *(.text.w3d_s20_play_sound_pair_800edca0) }
  .text.w3d_s20_play_sound_single_800edd1c 0x800edd1c : { *(.text.w3d_s20_play_sound_single_800edd1c) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; lbl_804aa8c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
