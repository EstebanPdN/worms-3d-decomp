/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10b_registry_acquire_801b3610)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801b4060 = 0x801b4060;
SECTIONS {
  .text.w3d_k10b_registry_acquire_801b3610 0x801b3610 : { *(.text.w3d_k10b_registry_acquire_801b3610) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
