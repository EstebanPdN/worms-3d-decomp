/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k1b_ctor_800bffb4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8040f8a8 = 0x8040f8a8;
w3d_ctor_801628b0 = 0x801628b0;
SECTIONS {
  .text.w3d_k1b_ctor_800bffb4 0x800bffb4 : { *(.text.w3d_k1b_ctor_800bffb4) }
  .sdata 0x804aada8 (NOLOAD) : {
    . = 0x0; lbl_804aada8 = .;
    . = 0x6ab4; lbl_804b185c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
