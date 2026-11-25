/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8004b3c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8004B3F0 = 0x8004b3f0;
lbl_80377108 = 0x80377108;
SECTIONS {
  .text.w3d_auto_8004b3c8 0x8004b3c8 : { *(.text.w3d_auto_8004b3c8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
