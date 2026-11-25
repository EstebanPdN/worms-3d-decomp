/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80064104)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178df0 = 0x80178df0;
w3d_f32_80379dc0 = 0x80379dc0;
SECTIONS {
  .text.w3d_fn_80064104 0x80064104 : { *(.text.w3d_fn_80064104) }
  .text.w3d_fn_80064198 0x80064198 : { *(.text.w3d_fn_80064198) }
  .text.w3d_fn_800649e8 0x800649e8 : { *(.text.w3d_fn_800649e8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
