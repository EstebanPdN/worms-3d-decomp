/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx14a_score_all_80011f30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
clear_8000b2f8 = 0x8000b2f8;
scale_8036a408 = 0x8036a408;
score_8000b344 = 0x8000b344;
weight_8036a40c = 0x8036a40c;
SECTIONS {
  .text.w3d_cx14a_score_all_80011f30 0x80011f30 : { *(.text.w3d_cx14a_score_all_80011f30) }
  .sdata 0x804aa750 (NOLOAD) : {
    . = 0x0; actors_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
