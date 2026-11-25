/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802e3178)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020EE9C = 0x8020ee9c;
fn_802E3110 = 0x802e3110;
lbl_80473B2C = 0x80473b2c;
SECTIONS {
  .text.w3d_auto_802e3178 0x802e3178 : { *(.text.w3d_auto_802e3178) }
  .sdata 0x804b10bc (NOLOAD) : {
    . = 0x0; lbl_804B10BC = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
