/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_stop_and_post_8009c5e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8009C758 = 0x8009c758;
fn_8009DD10 = 0x8009dd10;
fn_80126230 = 0x80126230;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_801797B4 = 0x801797b4;
fn_80341584 = 0x80341584;
lbl_80380210 = 0x80380210;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.s8_stop_and_post_8009c5e8 0x8009c5e8 : { *(.text.s8_stop_and_post_8009c5e8) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; lbl_804AA8C8 = .;
    . = 0x3748; lbl_804AE010 = .;
    . = 0x3760; lbl_804AE028 = .;
    . = 0x6e8c; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
