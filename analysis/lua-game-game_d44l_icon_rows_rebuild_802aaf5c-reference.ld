/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d44l_icon_rows_rebuild_802aaf5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3StrPCc = 0x8020bb54;
depth_80403b18 = 0x80403b18;
fn_8015adf4 = 0x8015adf4;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_80343584 = 0x80343584;
names_80403b2c = 0x80403b2c;
order_803d6b7c = 0x803d6b7c;
order_803d6bd0 = 0x803d6bd0;
order_803d6c24 = 0x803d6c24;
SECTIONS {
  .text.d44l_icon_rows_rebuild_802aaf5c 0x802aaf5c : { *(.text.d44l_icon_rows_rebuild_802aaf5c) }
  .rodata 0x803d6aa8 : { *(.rodata) }
  .sdata 0x804abb60 (NOLOAD) : {
    . = 0x0; base_804abb60 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
