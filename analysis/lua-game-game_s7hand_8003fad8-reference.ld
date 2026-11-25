/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8003fad8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8003FB0C = 0x8003fb0c;
lbl_804273EC = 0x804273ec;
SECTIONS {
  .text.w3d_auto_8003fad8 0x8003fad8 : { *(.text.w3d_auto_8003fad8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
