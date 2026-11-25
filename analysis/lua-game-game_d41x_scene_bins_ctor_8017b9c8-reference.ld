/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__18SceneBins_804127a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__as__3StrPCc = 0x8020bd38;
__vt_18SceneBins_804127a0 = 0x804127a0;
__vt_4Base = 0x80412870;
fn_8017d55c = 0x8017d55c;
fn_8017dcc0 = 0x8017dcc0;
fn_8017dfb4 = 0x8017dfb4;
fn_80206920 = 0x80206920;
fn_8020b648 = 0x8020b648;
fn_8020b680 = 0x8020b680;
fn_8020bb2c = 0x8020bb2c;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_8034cb64 = 0x8034cb64;
init__3Str = 0x803426b8;
make__8NameTempPCc = 0x8020bb54;
t_804a89d8 = 0x804a89d8;
t_804a8bd8 = 0x804a8bd8;
t_804a8dd8 = 0x804a8dd8;
tab_80456f14 = 0x80456f14;
type_804144e8 = 0x804144e8;
type_804149f0 = 0x804149f0;
type_804164c0 = 0x804164c0;
type_804190e0 = 0x804190e0;
SECTIONS {
  .text.__18SceneBins_804127a0 0x8017b9c8 : { *(.text.__18SceneBins_804127a0) }
  .rodata 0x803a7174 : { *(.rodata) }
  .sdata 0x804ab5e4 (NOLOAD) : {
    . = 0x0; lbl_804ab5e4 = .;
    . = 0x4; lbl_804ab5e8 = .;
    . = 0x8; lbl_804ab5ec = .;
    . = 0xc; lbl_804ab5f0 = .;
    . = 0x10; lbl_804ab5f4 = .;
    . = 0x14; lbl_804ab5f8 = .;
    . = 0x18; lbl_804ab5fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
