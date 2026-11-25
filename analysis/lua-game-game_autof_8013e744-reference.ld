/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8013e744)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800A830C = 0x800a830c;
fn_800E5CF0 = 0x800e5cf0;
fn_8013BD0C = 0x8013bd0c;
fn_8013F08C = 0x8013f08c;
lbl_8039F2F0 = 0x8039f2f0;
lbl_8039FCB4 = 0x8039fcb4;
lbl_8039FD28 = 0x8039fd28;
lbl_8039FD38 = 0x8039fd38;
lbl_8039FD40 = 0x8039fd40;
SECTIONS {
  .text.w3d_auto_8013e744 0x8013e744 : { *(.text.w3d_auto_8013e744) }
  .text.w3d_auto_8013ef98 0x8013ef98 : { *(.text.w3d_auto_8013ef98) }
  .text.w3d_auto_8013efe8 0x8013efe8 : { *(.text.w3d_auto_8013efe8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
