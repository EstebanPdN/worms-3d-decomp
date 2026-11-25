/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f2a_filter_grid_entries_800b2328)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002c73c = 0x8002c73c;
fn_8006096c = 0x8006096c;
fn_801ef048 = 0x801ef048;
SECTIONS {
  .text.w3d_f2a_filter_grid_entries_800b2328 0x800b2328 : { *(.text.w3d_f2a_filter_grid_entries_800b2328) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
