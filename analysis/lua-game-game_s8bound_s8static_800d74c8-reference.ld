/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_bound_800d74c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015f518 = 0x8015f518;
lbl_80389150 = 0x80389150;
lbl_80389164 = 0x80389164;
lbl_80389178 = 0x80389178;
lbl_8038918c = 0x8038918c;
SECTIONS {
  .text.s8_bound_800d74c8 0x800d74c8 : { *(.text.s8_bound_800d74c8) }
  .sdata 0x804aae64 (NOLOAD) : {
    . = 0x0; lbl_804aae64 = .;
    . = 0x3c20; lbl_804aea84 = .;
    . = 0x3c24; lbl_804aea88 = .;
    . = 0x3c28; lbl_804aea8c = .;
    . = 0x3c2c; lbl_804aea90 = .;
    . = 0x3c30; lbl_804aea94 = .;
    . = 0x3c34; lbl_804aea98 = .;
    . = 0x3c38; lbl_804aea9c = .;
    . = 0x3c3c; lbl_804aeaa0 = .;
    . = 0x3c40; lbl_804aeaa4 = .;
    . = 0x3c44; lbl_804aeaa8 = .;
    . = 0x3c4c; lbl_804aeab0 = .;
    . = 0x3c54; lbl_804aeab8 = .;
    . = 0x3c5c; lbl_804aeac0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
