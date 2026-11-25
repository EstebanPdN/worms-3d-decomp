/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28k_debug_tag_80215c58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802156c8 = 0x802156c8;
lbl_80400768 = 0x80400768;
strcmp = 0x802ef234;
strlen = 0x802ef9c0;
SECTIONS {
  .text.w3d_d28k_debug_tag_80215c58 0x80215c58 : { *(.text.w3d_d28k_debug_tag_80215c58) }
  .sdata 0x804aba6c (NOLOAD) : {
    . = 0x0; lbl_804aba6c = .;
    . = 0x14; lbl_804aba80 = .;
    . = 0x4c54; lbl_804b06c0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
