/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8006704c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_empty_800672c0 = 0x800672c0;
w3d_f32_8037a090 = 0x8037a090;
w3d_fn_800672c4 = 0x800672c4;
SECTIONS {
  .text.w3d_fn_8006704c 0x8006704c : { *(.text.w3d_fn_8006704c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
