/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f12b_clear_globals_801fd238)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__dl__19F12b_Clear1748_ItemPv = 0x801fe1f8;
__dl__20F12b_Clear1748_SmallPv = 0x801fe1f8;
fn_8020c5c4 = 0x8020c5c4;
fn_80210990 = 0x80210990;
fn_80341588 = 0x80341588;
lbl_8045e944 = 0x8045e944;
lbl_8045e970 = 0x8045e970;
lbl_8045e99c = 0x8045e99c;
lbl_8045e9ac = 0x8045e9ac;
vt_80418490 = 0x80418490;
vt_804192d8 = 0x804192d8;
vt_804192f8 = 0x804192f8;
SECTIONS {
  .text.f12b_clear_globals_801fd238 0x801fd238 : { *(.text.f12b_clear_globals_801fd238) }
  .sdata 0x804b05e0 (NOLOAD) : {
    . = 0x0; lbl_804b05e0 = .;
    . = 0x4; lbl_804b05e4 = .;
    . = 0x8; lbl_804b05e8 = .;
    . = 0x18; lbl_804b05f8 = .;
    . = 0x1c; lbl_804b05fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
