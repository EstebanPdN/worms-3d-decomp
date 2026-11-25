/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80268f18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_80162BA8 = 0x80162ba8;
fn_802691FC = 0x802691fc;
fn_80269694 = 0x80269694;
fn_8026B3F0 = 0x8026b3f0;
fn_8026BDF0 = 0x8026bdf0;
fn_8026C008 = 0x8026c008;
fn_8026C54C = 0x8026c54c;
fn_8026CC20 = 0x8026cc20;
fn_8026D8A0 = 0x8026d8a0;
fn_802AFF9C = 0x802aff9c;
fn_802B264C = 0x802b264c;
SECTIONS {
  .text.w3d_auto_80268f18 0x80268f18 : { *(.text.w3d_auto_80268f18) }
  .sdata 0x804abb7c (NOLOAD) : {
    . = 0x0; lbl_804ABB7C = .;
    . = 0x4f48; lbl_804B0AC4 = .;
    . = 0x4f50; lbl_804B0ACC = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
