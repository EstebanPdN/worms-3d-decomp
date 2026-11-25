/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802e0238)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8041C9A0 = 0x8041c9a0;
SECTIONS {
  .text.w3d_auto_802e0238 0x802e0238 : { *(.text.w3d_auto_802e0238) }
  .sdata 0x804b190c (NOLOAD) : {
    . = 0x0; lbl_804B190C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
