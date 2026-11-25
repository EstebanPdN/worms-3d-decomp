/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8006bce4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_fn_8006bce4 0x8006bce4 : { *(.text.w3d_fn_8006bce4) }
  .sdata 0x804aaab0 (NOLOAD) : {
    . = 0x0; w3d_busy_804aaab0 = .;
    . = 0x6d3c; w3d_context_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
