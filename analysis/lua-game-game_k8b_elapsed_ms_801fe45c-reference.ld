/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_elapsed_ms_801fe45c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__udivdi3 = 0x802f4460;
fn_80300aa0 = 0x80300aa0;
SECTIONS {
  .text.w3d_k8b_elapsed_ms_801fe45c 0x801fe45c : { *(.text.w3d_k8b_elapsed_ms_801fe45c) }
  .sdata 0x804b0628 (NOLOAD) : {
    . = 0x0; lbl_804b0628 = .;
    . = 0x8; lbl_804b0630 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
