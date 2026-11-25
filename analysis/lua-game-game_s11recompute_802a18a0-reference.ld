/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802a18a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800A830C = 0x800a830c;
fn_8015F65C = 0x8015f65c;
fn_8029E02C = 0x8029e02c;
fn_802A1A80 = 0x802a1a80;
fn_802A1BBC = 0x802a1bbc;
fn_802A1C90 = 0x802a1c90;
fn_802B264C = 0x802b264c;
SECTIONS {
  .text.w3d_auto_802a18a0 0x802a18a0 : { *(.text.w3d_auto_802a18a0) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; lbl_804ABB48 = .;
    . = 0x5328; lbl_804B0E70 = .;
    . = 0x5330; lbl_804B0E78 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
