/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28k_heap_open_802168c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80400770 = 0x80400770;
SECTIONS {
  .text.w3d_d28k_heap_open_802168c4 0x802168c4 : { *(.text.w3d_d28k_heap_open_802168c4) }
  .sdata 0x804aba6c (NOLOAD) : {
    . = 0x0; lbl_804aba6c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
