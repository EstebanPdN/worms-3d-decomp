/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20desc_801c1fcc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ebf38 = 0x801ebf38;
fn_801eff8c = 0x801eff8c;
lbl_803ac6a8 = 0x803ac6a8;
lbl_803ac6d0 = 0x803ac6d0;
lbl_803fe464 = 0x803fe464;
lbl_8045d3cc = 0x8045d3cc;
lbl_8045e004 = 0x8045e004;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20desc_801c1fcc 0x801c1fcc : { *(.text.w3d_s20desc_801c1fcc) }
  .sdata 0x804b0460 (NOLOAD) : {
    . = 0x0; lbl_804b0460 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
