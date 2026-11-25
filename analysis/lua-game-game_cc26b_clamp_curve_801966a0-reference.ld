/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc26b_clamp_curve_801966a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc26b_constant_803a84c4 = 0x803a84c4;
cc26b_constant_803a84c8 = 0x803a84c8;
cc26b_constant_803a84cc = 0x803a84cc;
cc26b_constant_803a84d0 = 0x803a84d0;
cc26b_constant_803a84d4 = 0x803a84d4;
cc26b_fn_80196668 = 0x80196668;
cc26b_fn_8019705c = 0x8019705c;
cc26b_fn_80197208 = 0x80197208;
cc26b_global_804a91e4 = 0x804a91e4;
cc26b_global_804a91f4 = 0x804a91f4;
SECTIONS {
  .text.w3d_cc26b_clamp_curve_801966a0 0x801966a0 : { *(.text.w3d_cc26b_clamp_curve_801966a0) }
  .sdata 0x804ab6ec (NOLOAD) : {
    . = 0x0; cc26b_global_804ab6ec = .;
    . = 0x61e4; cc26b_global_804b18d0 = .;
    . = 0x61e8; cc26b_global_804b18d4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
