/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802a3058)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80165254 = 0x80165254;
fn_802A31FC = 0x802a31fc;
fn_802A32E0 = 0x802a32e0;
fn_802A3784 = 0x802a3784;
fn_802B0B84 = 0x802b0b84;
SECTIONS {
  .text.w3d_auto_802a3058 0x802a3058 : { *(.text.w3d_auto_802a3058) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
