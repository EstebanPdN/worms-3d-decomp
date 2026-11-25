/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_sinks_dispatch_8002daf0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_constant_8015fb2c = 0x8015fb2c;
w3d_fn_8004e2a4 = 0x8004e2a4;
w3d_fn_8004e384 = 0x8004e384;
SECTIONS {
  .text.w3d_k8a_sinks_dispatch_8002daf0 0x8002daf0 : { *(.text.w3d_k8a_sinks_dispatch_8002daf0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
