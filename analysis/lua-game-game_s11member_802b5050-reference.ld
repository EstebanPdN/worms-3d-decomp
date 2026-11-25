/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802b5050)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
call__18S11Method_802B4E8C = 0x802b4e8c;
fn_802B4EF4__FPc = 0x802b4ef4;
SECTIONS {
  .text.w3d_auto_802b5050 0x802b5050 : { *(.text.w3d_auto_802b5050) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
