/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32l_cube_mesh_setup_802bb360)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4Str2PCc = 0x8020bb54;
fn_8015ae3c = 0x8015ae3c;
fn_80172050 = 0x80172050;
fn_801750d4 = 0x801750d4;
fn_801d0858 = 0x801d0858;
fn_801d086c = 0x801d086c;
fn_801d0898 = 0x801d0898;
fn_801ef048 = 0x801ef048;
fn_801ef174 = 0x801ef174;
fn_8020b680 = 0x8020b680;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_80343808 = 0x80343808;
fn_8034bf48 = 0x8034bf48;
lbl_80414518 = 0x80414518;
lbl_804146e0 = 0x804146e0;
lbl_80414780 = 0x80414780;
lbl_80414830 = 0x80414830;
lbl_80414870 = 0x80414870;
lbl_804148d0 = 0x804148d0;
lbl_80415b00 = 0x80415b00;
SECTIONS {
  .text.d32l_cube_mesh_setup_802bb360 0x802bb360 : { *(.text.d32l_cube_mesh_setup_802bb360) }
  .rodata 0x803d8254 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
