/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802b16c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80264658 = 0x80264658;
SECTIONS {
  .text.w3d_auto_802b16c4 0x802b16c4 : { *(.text.w3d_auto_802b16c4) }
  .sdata 0x804abb44 (NOLOAD) : {
    . = 0x0; lbl_804ABB44 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
