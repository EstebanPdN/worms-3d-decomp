/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_acquire_pooled_80171fa0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ef048 = 0x801ef048;
fn_801f5724 = 0x801f5724;
SECTIONS {
  .text.w3d_s20_acquire_pooled_80171fa0 0x80171fa0 : { *(.text.w3d_s20_acquire_pooled_80171fa0) }
  .text.w3d_s20_acquire_pooled_80171ff8 0x80171ff8 : { *(.text.w3d_s20_acquire_pooled_80171ff8) }
  .text.w3d_s20_dispatch_stored_801a3c6c 0x801a3c6c : { *(.text.w3d_s20_dispatch_stored_801a3c6c) }
  .text.w3d_s20_set_quad_and_forward_801a55f0 0x801a55f0 : { *(.text.w3d_s20_set_quad_and_forward_801a55f0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
