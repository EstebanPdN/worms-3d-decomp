/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8006b53c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_fn_8006ab48 = 0x8006ab48;
w3d_fn_800a7ea0 = 0x800a7ea0;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80164514 = 0x80164514;
w3d_fn_8020b680 = 0x8020b680;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_str_8037bb14 = 0x8037bb14;
w3d_str_8037bd3c = 0x8037bd3c;
w3d_type_8040fa58 = 0x8040fa58;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_fn_8006b53c 0x8006b53c : { *(.text.w3d_fn_8006b53c) }
  .text.w3d_fn_8006b5fc 0x8006b5fc : { *(.text.w3d_fn_8006b5fc) }
  .text.w3d_fn_8006b6bc 0x8006b6bc : { *(.text.w3d_fn_8006b6bc) }
  .text.w3d_fn_8006b77c 0x8006b77c : { *(.text.w3d_fn_8006b77c) }
  .sdata 0x804ad74c (NOLOAD) : {
    . = 0x0; w3d_message_804ad74c = .;
    . = 0x8; w3d_message_804ad754 = .;
    . = 0x58; w3d_message_804ad7a4 = .;
    . = 0x68; w3d_message_804ad7b4 = .;
    . = 0x70; w3d_message_804ad7bc = .;
    . = 0x78; w3d_message_804ad7c4 = .;
    . = 0x4008; w3d_queue_804b1754 = .;
    . = 0x403c; w3d_context_804b1788 = .;
    . = 0x4040; w3d_manager_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
