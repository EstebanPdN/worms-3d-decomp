/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802c23f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_8015FD1C = 0x8015fd1c;
fn_802C28A0 = 0x802c28a0;
fn_802C29D0 = 0x802c29d0;
fn_802C3B20 = 0x802c3b20;
fn_802C3C80 = 0x802c3c80;
fn_802C3DE4 = 0x802c3de4;
fn_802C3EF0 = 0x802c3ef0;
fn_802C40B4 = 0x802c40b4;
SECTIONS {
  .text.w3d_auto_802c23f4 0x802c23f4 : { *(.text.w3d_auto_802c23f4) }
  .sdata 0x804abb5c (NOLOAD) : {
    . = 0x0; lbl_804ABB5C = .;
    . = 0x5514; lbl_804B1070 = .;
    . = 0x551c; lbl_804B1078 = .;
    . = 0x5524; lbl_804B1080 = .;
    . = 0x552c; lbl_804B1088 = .;
    . = 0x5534; lbl_804B1090 = .;
    . = 0x553c; lbl_804B1098 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
