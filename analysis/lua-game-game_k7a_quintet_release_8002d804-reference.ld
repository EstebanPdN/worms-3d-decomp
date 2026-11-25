/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k7a_quintet_release_8002d804)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_8004dc38 = 0x8004dc38;
w3d_registry_unlink_8002d734 = 0x8002d734;
w3d_vtable_8040e430 = 0x8040e430;
SECTIONS {
  .text.w3d_k7a_quintet_release_8002d804 0x8002d804 : { *(.text.w3d_k7a_quintet_release_8002d804) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
