/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8013f2a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800E5CF0 = 0x800e5cf0;
fn_800FC6DC = 0x800fc6dc;
fn_801359EC = 0x801359ec;
fn_80139158 = 0x80139158;
fn_8013F08C = 0x8013f08c;
fn_8013FECC = 0x8013fecc;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80162C20 = 0x80162c20;
lbl_8039FD54 = 0x8039fd54;
lbl_8039FD70 = 0x8039fd70;
lbl_8039FD7C = 0x8039fd7c;
lbl_8039FDC0 = 0x8039fdc0;
lbl_8039FDEC = 0x8039fdec;
lbl_8039FDF0 = 0x8039fdf0;
lbl_8039FDF4 = 0x8039fdf4;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.w3d_auto_8013f2a4 0x8013f2a4 : { *(.text.w3d_auto_8013f2a4) }
  .text.w3d_auto_8013f50c 0x8013f50c : { *(.text.w3d_auto_8013f50c) }
  .text.w3d_auto_8013f884 0x8013f884 : { *(.text.w3d_auto_8013f884) }
  .text.w3d_auto_8013f8e8 0x8013f8e8 : { *(.text.w3d_auto_8013f8e8) }
  .sdata 0x804ab15c (NOLOAD) : {
    . = 0x0; lbl_804AB15C = .;
    . = 0x4; lbl_804AB160 = .;
    . = 0x8; lbl_804AB164 = .;
    . = 0xc; lbl_804AB168 = .;
    . = 0x180; lbl_804AB2DC = .;
    . = 0x184; lbl_804AB2E0 = .;
    . = 0x260; lbl_804AB3BC = .;
    . = 0x4884; lbl_804AF9E0 = .;
    . = 0x65f8; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
