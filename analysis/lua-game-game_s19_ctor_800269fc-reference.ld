/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_ctor_800269fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8040e008 = 0x8040e008;
w3d_actor_base_initialize = 0x80161014;
SECTIONS {
  .text.s19_ctor_800269fc 0x800269fc : { *(.text.s19_ctor_800269fc) }
  .rodata 0x8036cadc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
