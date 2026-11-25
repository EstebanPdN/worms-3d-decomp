/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_state_reset_80167fe0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80307558 = 0x80307558;
w3d_state_apply_8016797c = 0x8016797c;
SECTIONS {
  .text.w3d_k4b_state_reset_80167fe0 0x80167fe0 : { *(.text.w3d_k4b_state_reset_80167fe0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
