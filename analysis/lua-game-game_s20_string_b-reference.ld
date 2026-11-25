/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_set_title_800f2f94)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800f6afc = 0x800f6afc;
fn_8020bb2c = 0x8020bb2c;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_s20_set_title_800f2f94 0x800f2f94 : { *(.text.w3d_s20_set_title_800f2f94) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
