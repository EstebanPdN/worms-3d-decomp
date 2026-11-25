/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_post_object_events_800ed090)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800C1620 = 0x800c1620;
fn_800ED9C8 = 0x800ed9c8;
fn_80125FDC = 0x80125fdc;
fn_8015F5A0 = 0x8015f5a0;
fn_8015FC58 = 0x8015fc58;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_801797B4 = 0x801797b4;
fn_80341584 = 0x80341584;
SECTIONS {
  .text.s8_post_object_events_800ed090 0x800ed090 : { *(.text.s8_post_object_events_800ed090) }
  .sdata 0x804aef00 (NOLOAD) : {
    . = 0x0; lbl_804AEF00 = .;
    . = 0x2854; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
