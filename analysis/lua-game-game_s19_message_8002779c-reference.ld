/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_handle_message_8002779c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80027d20 = 0x80027d20;
w3d_auto_8016293c = 0x8016293c;
w3d_message_id_equals_cache = 0x8015f65c;
SECTIONS {
  .text.s19_handle_message_8002779c 0x8002779c : { *(.text.s19_handle_message_8002779c) }
  .sdata 0x804acb94 (NOLOAD) : {
    . = 0x0; lbl_804acb94 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
