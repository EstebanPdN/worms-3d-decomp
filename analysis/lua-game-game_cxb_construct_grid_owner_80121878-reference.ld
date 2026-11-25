/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cxb_construct_grid_owner_80121878)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015fef0 = 0x8015fef0;
fn_803426b8 = 0x803426b8;
fn_80343740 = 0x80343740;
lbl_80410b18 = 0x80410b18;
SECTIONS {
  .text.cxb_construct_grid_owner_80121878 0x80121878 : { *(.text.cxb_construct_grid_owner_80121878) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
