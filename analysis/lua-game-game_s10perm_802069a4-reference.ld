/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802069a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801FCD74 = 0x801fcd74;
SECTIONS {
  .text.w3d_auto_802069a4 0x802069a4 : { *(.text.w3d_auto_802069a4) }
  .sdata 0x804ab99c (NOLOAD) : {
    . = 0x0; lbl_804AB99C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
