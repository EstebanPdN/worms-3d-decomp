/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_ctor_8002824c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8040e208 = 0x8040e208;
w3d_ctor_8015fef0 = 0x8015fef0;
SECTIONS {
  .text.s19_ctor_8002824c 0x8002824c : { *(.text.s19_ctor_8002824c) }
  .rodata 0x8036cd78 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
