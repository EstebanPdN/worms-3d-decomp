/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx14a_score_others_80012018)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
clear_8000b2f8 = 0x8000b2f8;
scale_8036a430 = 0x8036a430;
score_8000b344 = 0x8000b344;
weight_8036a434 = 0x8036a434;
SECTIONS {
  .text.w3d_cx14a_score_others_80012018 0x80012018 : { *(.text.w3d_cx14a_score_others_80012018) }
  .sdata 0x804aa6c0 (NOLOAD) : {
    . = 0x0; team_804aa6c0 = .;
    . = 0x90; actors_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
