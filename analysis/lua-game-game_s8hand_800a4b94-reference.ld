/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_mesh_update_800a4b94)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800a4da4 = 0x800a4da4;
fn_8015fd1c = 0x8015fd1c;
fn_80181ccc = 0x80181ccc;
fn_80343584 = 0x80343584;
SECTIONS {
  .text.s8_mesh_update_800a4b94 0x800a4b94 : { *(.text.s8_mesh_update_800a4b94) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
