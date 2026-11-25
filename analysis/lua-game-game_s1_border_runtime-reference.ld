/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80063434)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_fn_800fc43c = 0x800fc43c;
w3d_fn_801613f0 = 0x801613f0;
w3d_message_post_current = 0x8016239c;
w3d_message_vtable_8040db38 = 0x8040db38;
w3d_str_80379b78 = 0x80379b78;
SECTIONS {
  .text.w3d_fn_80063434 0x80063434 : { *(.text.w3d_fn_80063434) }
  .sdata 0x804ad530 (NOLOAD) : {
    . = 0x0; w3d_message_804ad530 = .;
    . = 0x10; w3d_message_804ad540 = .;
    . = 0x4224; w3d_queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
