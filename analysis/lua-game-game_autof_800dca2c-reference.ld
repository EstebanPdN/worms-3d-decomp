/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800dca2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80162BC8 = 0x80162bc8;
lbl_80389A40 = 0x80389a40;
lbl_80389A44 = 0x80389a44;
SECTIONS {
  .text.w3d_auto_800dca2c 0x800dca2c : { *(.text.w3d_auto_800dca2c) }
  .rodata 0x80389a38 : { *(.rodata) }
  .sdata 0x804aec54 (NOLOAD) : {
    . = 0x0; lbl_804AEC54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
