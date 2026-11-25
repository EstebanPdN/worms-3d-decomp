/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_engine_get_context)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_engine_get_context 0x80165254 : { *(.text.w3d_engine_get_context) }
  .text.w3d_actor_from_handle 0x8034b974 : { *(.text.w3d_actor_from_handle) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; w3d_engine_context = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
