/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f1a_copy_selected_vectors_800bd808)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800b5fc0 = 0x800b5fc0;
fn_800bcdec = 0x800bcdec;
lbl_80382cf8 = 0x80382cf8;
lbl_8043bb64 = 0x8043bb64;
w3d_collect_selected_800bcd6c = 0x800bcd6c;
SECTIONS {
  .text.w3d_f1a_copy_selected_vectors_800bd808 0x800bd808 : { *(.text.w3d_f1a_copy_selected_vectors_800bd808) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
