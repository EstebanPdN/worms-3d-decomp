/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_msg_init_800b92a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8040db38 = 0x8040db38;
w3d_cached_message_id = 0x8015f5a0;
SECTIONS {
  .text.s19_msg_init_800b92a4 0x800b92a4 : { *(.text.s19_msg_init_800b92a4) }
  .sdata 0x804ae510 (NOLOAD) : {
    . = 0x0; lbl_804ae510 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
