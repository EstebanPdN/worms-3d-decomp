/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8002765c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80126184 = 0x80126184;
fn_801628B0 = 0x801628b0;
lbl_8040E1C8 = 0x8040e1c8;
SECTIONS {
  .text.w3d_auto_8002765c 0x8002765c : { *(.text.w3d_auto_8002765c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
