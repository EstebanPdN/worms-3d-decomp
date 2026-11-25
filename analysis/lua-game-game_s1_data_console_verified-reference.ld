/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8004fc60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcmp = 0x802ef234;
w3d_auto_8016293c = 0x8016293c;
w3d_empty_80050978 = 0x80050978;
w3d_fn_8004fd6c = 0x8004fd6c;
w3d_fn_8004fda4 = 0x8004fda4;
w3d_fn_800507b8 = 0x800507b8;
w3d_fn_802cba50 = 0x802cba50;
w3d_fn_802cbacc = 0x802cbacc;
w3d_fn_802cbb5c = 0x802cbb5c;
w3d_fn_802cbc68 = 0x802cbc68;
w3d_fn_802ccb40 = 0x802ccb40;
w3d_fn_802cd2e0 = 0x802cd2e0;
SECTIONS {
  .text.w3d_fn_8004fc60 0x8004fc60 : { *(.text.w3d_fn_8004fc60) }
  .text.w3d_fn_8004fcc4 0x8004fcc4 : { *(.text.w3d_fn_8004fcc4) }
  .text.w3d_fn_800504d0 0x800504d0 : { *(.text.w3d_fn_800504d0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
