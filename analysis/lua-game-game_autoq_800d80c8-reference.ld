/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800d80c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800D8B4C = 0x800d8b4c;
fn_800D98A4 = 0x800d98a4;
fn_800ED090 = 0x800ed090;
fn_8015F5A0 = 0x8015f5a0;
fn_80162024 = 0x80162024;
fn_80165254 = 0x80165254;
fn_801797B4 = 0x801797b4;
fn_80341584 = 0x80341584;
SECTIONS {
  .text.w3d_auto_800d80c8 0x800d80c8 : { *(.text.w3d_auto_800d80c8) }
  .sdata 0x804aeaf0 (NOLOAD) : {
    . = 0x0; lbl_804AEAF0 = .;
    . = 0x8; lbl_804AEAF8 = .;
    . = 0x10; lbl_804AEB00 = .;
    . = 0x18; lbl_804AEB08 = .;
    . = 0x20; lbl_804AEB10 = .;
    . = 0x28; lbl_804AEB18 = .;
    . = 0x30; lbl_804AEB20 = .;
    . = 0x48; lbl_804AEB38 = .;
    . = 0x50; lbl_804AEB40 = .;
    . = 0x68; lbl_804AEB58 = .;
    . = 0x80; lbl_804AEB70 = .;
    . = 0x88; lbl_804AEB78 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
