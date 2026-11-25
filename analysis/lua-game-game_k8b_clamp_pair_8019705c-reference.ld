/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_clamp_pair_8019705c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_k8b_clamp_pair_8019705c 0x8019705c : { *(.text.w3d_k8b_clamp_pair_8019705c) }
  .rodata 0x803a84f8 : { *(.rodata) }
  .sdata 0x804ab6e4 (NOLOAD) : {
    . = 0x0; lbl_804ab6e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
