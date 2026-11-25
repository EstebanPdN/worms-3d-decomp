/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24e_sin_cos_801f3db0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
constant_803b0e94 = 0x803b0e94;
constant_803b0e98 = 0x803b0e98;
constant_803b0ea8 = 0x803b0ea8;
constant_803b0eac = 0x803b0eac;
constant_803b0eb0 = 0x803b0eb0;
constant_803b0eb4 = 0x803b0eb4;
constant_803b0eb8 = 0x803b0eb8;
constant_803b0ebc = 0x803b0ebc;
SECTIONS {
  .text.w3d_d24e_sin_cos_801f3db0 0x801f3db0 : { *(.text.w3d_d24e_sin_cos_801f3db0) }
  .rodata 0x803b0ea0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
