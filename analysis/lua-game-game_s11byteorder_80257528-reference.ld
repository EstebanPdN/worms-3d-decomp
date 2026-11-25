/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80257528)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801EA0EC = 0x801ea0ec;
fn_8025C2D8 = 0x8025c2d8;
lbl_8041B978 = 0x8041b978;
SECTIONS {
  .text.w3d_auto_80257528 0x80257528 : { *(.text.w3d_auto_80257528) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
