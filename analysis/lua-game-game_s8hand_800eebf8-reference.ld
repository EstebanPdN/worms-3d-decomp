/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_countdown_events_800eebf8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800C53A0 = 0x800c53a0;
fn_800EE720 = 0x800ee720;
fn_800FCEA0 = 0x800fcea0;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80165254 = 0x80165254;
fn_801797B4 = 0x801797b4;
fn_802EF234 = 0x802ef234;
fn_80341584 = 0x80341584;
lbl_8038BDAC = 0x8038bdac;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.s8_countdown_events_800eebf8 0x800eebf8 : { *(.text.s8_countdown_events_800eebf8) }
  .sdata 0x804aef5c (NOLOAD) : {
    . = 0x0; lbl_804AEF5C = .;
    . = 0x20; lbl_804AEF7C = .;
    . = 0x50; lbl_804AEFAC = .;
    . = 0x80; lbl_804AEFDC = .;
    . = 0x90; lbl_804AEFEC = .;
    . = 0xb0; lbl_804AF00C = .;
    . = 0x27f8; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
