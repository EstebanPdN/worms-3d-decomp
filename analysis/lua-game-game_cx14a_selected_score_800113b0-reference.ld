/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx14a_selected_score_800113b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
scale_8036a350 = 0x8036a350;
score_8000b344 = 0x8000b344;
SECTIONS {
  .text.w3d_cx14a_selected_score_800113b0 0x800113b0 : { *(.text.w3d_cx14a_selected_score_800113b0) }
  .rodata 0x8036a348 : { *(.rodata) }
  .sdata 0x804aa6e8 (NOLOAD) : {
    . = 0x0; selected_804aa6e8 = .;
    . = 0x68; actors_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
