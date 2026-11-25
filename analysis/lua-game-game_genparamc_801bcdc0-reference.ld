/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_construct_vectors_801bcdc0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801bcb0c = 0x801bcb0c;
fn_801c0700 = 0x801c0700;
lbl_803ab9e8 = 0x803ab9e8;
lbl_803aba60 = 0x803aba60;
lbl_803ac5e0 = 0x803ac5e0;
lbl_80414dd0 = 0x80414dd0;
lbl_80415230 = 0x80415230;
lbl_80415258 = 0x80415258;
SECTIONS {
  .text.w3d_construct_vectors_801bcdc0 0x801bcdc0 : { *(.text.w3d_construct_vectors_801bcdc0) }
  .text.w3d_construct_vectors_801bcfec 0x801bcfec : { *(.text.w3d_construct_vectors_801bcfec) }
  .text.w3d_construct_vectors_801c1638 0x801c1638 : { *(.text.w3d_construct_vectors_801c1638) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
