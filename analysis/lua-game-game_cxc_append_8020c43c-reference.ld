/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cxc_append_8020c43c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020bb2c = 0x8020bb2c;
fn_8020bc88 = 0x8020bc88;
fn_802eee50 = 0x802eee50;
SECTIONS {
  .text.cxc_append_8020c43c 0x8020c43c : { *(.text.cxc_append_8020c43c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
