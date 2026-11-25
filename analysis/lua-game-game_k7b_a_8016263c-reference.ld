/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k7b_static_init_8016263c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8016149c = 0x8016149c;
lbl_803618c0 = 0x803618c0;
lbl_803618f0 = 0x803618f0;
lbl_803e8878 = 0x803e8878;
lbl_80455244 = 0x80455244;
lbl_80455250 = 0x80455250;
w3d_auto_801629f8 = 0x801629f8;
SECTIONS {
  .text.w3d_k7b_static_init_8016263c 0x8016263c : { *(.text.w3d_k7b_static_init_8016263c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
