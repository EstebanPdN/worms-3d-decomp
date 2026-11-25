/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9b_registry_run_pending_80200b54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_cx9b_registry_run_pending_80200b54 0x80200b54 : { *(.text.w3d_cx9b_registry_run_pending_80200b54) }
  .sdata 0x804b18e8 (NOLOAD) : {
    . = 0x0; registry_804b18e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
