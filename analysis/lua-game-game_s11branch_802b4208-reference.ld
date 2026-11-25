/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802b4208)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_802AFF9C = 0x802aff9c;
fn_802B1258 = 0x802b1258;
fn_802B22B0 = 0x802b22b0;
fn_802B264C = 0x802b264c;
fn_802B43A0 = 0x802b43a0;
fn_802B46F4 = 0x802b46f4;
fn_802B4E8C = 0x802b4e8c;
fn_802B4F88 = 0x802b4f88;
SECTIONS {
  .text.w3d_auto_802b4208 0x802b4208 : { *(.text.w3d_auto_802b4208) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; lbl_804ABB48 = .;
    . = 0x54b0; lbl_804B0FF8 = .;
    . = 0x54b8; lbl_804B1000 = .;
    . = 0x54c0; lbl_804B1008 = .;
    . = 0x54c8; lbl_804B1010 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
