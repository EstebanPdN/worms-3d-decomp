/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_post_selected_800de7f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_801613f0 = 0x801613f0;
w3d_auto_8003a264 = 0x8003a264;
w3d_message_post_current = 0x8016239c;
SECTIONS {
  .text.s19_post_selected_800de7f0 0x800de7f0 : { *(.text.s19_post_selected_800de7f0) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . = 0x4c; lbl_804b17a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
