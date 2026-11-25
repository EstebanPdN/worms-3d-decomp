/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26a_timer_next_80040f18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_80040b0c = 0x80040b0c;
w3d_fn_80040d84 = 0x80040d84;
SECTIONS {
  .text.w3d_d26a_timer_next_80040f18 0x80040f18 : { *(.text.w3d_d26a_timer_next_80040f18) }
  .rodata 0x80374790 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
