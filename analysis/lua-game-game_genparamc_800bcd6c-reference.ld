/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_collect_selected_800bcd6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800b5f2c = 0x800b5f2c;
fn_800b5fc0 = 0x800b5fc0;
lbl_8043bb64 = 0x8043bb64;
SECTIONS {
  .text.w3d_collect_selected_800bcd6c 0x800bcd6c : { *(.text.w3d_collect_selected_800bcd6c) }
  .text.w3d_collect_selected_800bd8a0 0x800bd8a0 : { *(.text.w3d_collect_selected_800bd8a0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
