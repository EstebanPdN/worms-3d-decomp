/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d33f_border_mesh_8029358c_x_8029358c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801750d4 = 0x801750d4;
fn_801ef048 = 0x801ef048;
fn_801f55ec = 0x801f55ec;
lbl_80401880 = 0x80401880;
SECTIONS {
  .text.d33f_border_mesh_8029358c_x_8029358c 0x8029358c : { *(.text.d33f_border_mesh_8029358c_x_8029358c) }
  .rodata 0x803d06f0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
