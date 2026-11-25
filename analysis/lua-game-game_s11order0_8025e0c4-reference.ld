/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8025e0c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801FE1F8 = 0x801fe1f8;
fn_80287C88 = 0x80287c88;
SECTIONS {
  .text.w3d_auto_8025e0c4 0x8025e0c4 : { *(.text.w3d_auto_8025e0c4) }
  .sdata 0x804abbc8 (NOLOAD) : {
    . = 0x0; lbl_804ABBC8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
