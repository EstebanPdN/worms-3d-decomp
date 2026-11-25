/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cxc2_records_8020fac8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802eefe0 = 0x802eefe0;
lbl_8040c980 = 0x8040c980;
lbl_8040c990 = 0x8040c990;
lbl_80463bbc = 0x80463bbc;
SECTIONS {
  .text.cxc2_records_8020fac8 0x8020fac8 : { *(.text.cxc2_records_8020fac8) }
  .sdata 0x804b06b4 (NOLOAD) : {
    . = 0x0; lbl_804b06b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
