/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8004035c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_80040f18 = 0x80040f18;
w3d_fn_80040ff4 = 0x80040ff4;
SECTIONS {
  .text.w3d_fn_8004035c 0x8004035c : { *(.text.w3d_fn_8004035c) }
  .text.w3d_fn_80040440 0x80040440 : { *(.text.w3d_fn_80040440) }
  .text.w3d_fn_800405d4 0x800405d4 : { *(.text.w3d_fn_800405d4) }
  .text.w3d_fn_800406b8 0x800406b8 : { *(.text.w3d_fn_800406b8) }
  .text.w3d_fn_8004084c 0x8004084c : { *(.text.w3d_fn_8004084c) }
  .text.w3d_fn_80040b0c 0x80040b0c : { *(.text.w3d_fn_80040b0c) }
  .text.w3d_fn_80040ca0 0x80040ca0 : { *(.text.w3d_fn_80040ca0) }
  .text.w3d_fn_80040d84 0x80040d84 : { *(.text.w3d_fn_80040d84) }
  .rodata 0x80374750 : { *(.rodata) }
  .sdata 0x804b17d4 (NOLOAD) : {
    . = 0x0; w3d_f32_804b17d4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
