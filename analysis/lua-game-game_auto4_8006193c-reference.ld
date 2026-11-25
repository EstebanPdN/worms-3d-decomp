/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8006193c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80061A80 = 0x80061a80;
fn_80061CD4 = 0x80061cd4;
fn_800681D4 = 0x800681d4;
fn_8006823C = 0x8006823c;
fn_80068240 = 0x80068240;
fn_80072FE4 = 0x80072fe4;
fn_8007304C = 0x8007304c;
fn_80073050 = 0x80073050;
fn_80096C30 = 0x80096c30;
fn_80096DA8 = 0x80096da8;
fn_80096DB4 = 0x80096db4;
fn_8009723C = 0x8009723c;
fn_8015F620 = 0x8015f620;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_8015FD1C = 0x8015fd1c;
fn_8016293C = 0x8016293c;
SECTIONS {
  .text.w3d_auto_8006193c 0x8006193c : { *(.text.w3d_auto_8006193c) }
  .text.w3d_auto_80068100 0x80068100 : { *(.text.w3d_auto_80068100) }
  .text.w3d_auto_80072f10 0x80072f10 : { *(.text.w3d_auto_80072f10) }
  .text.w3d_auto_80096b6c 0x80096b6c : { *(.text.w3d_auto_80096b6c) }
  .sdata 0x804ad4f4 (NOLOAD) : {
    . = 0x0; lbl_804AD4F4 = .;
    . = 0x104; lbl_804AD5F8 = .;
    . = 0x10c; lbl_804AD600 = .;
    . = 0x470; lbl_804AD964 = .;
    . = 0x478; lbl_804AD96C = .;
    . = 0xa60; lbl_804ADF54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
