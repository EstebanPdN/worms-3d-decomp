/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8004c51c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_fn_8004c7a0 = 0x8004c7a0;
w3d_fn_8004cda4 = 0x8004cda4;
w3d_fn_8004d10c = 0x8004d10c;
w3d_fn_800fc3b0 = 0x800fc3b0;
w3d_fn_800fc550 = 0x800fc550;
w3d_fn_800fc710 = 0x800fc710;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80178474 = 0x80178474;
w3d_message_int_init = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_message_vtable_8040db38 = 0x8040db38;
w3d_str_803772f0 = 0x803772f0;
w3d_str_80377308 = 0x80377308;
SECTIONS {
  .text.w3d_fn_8004c51c 0x8004c51c : { *(.text.w3d_fn_8004c51c) }
  .text.w3d_fn_8004c598 0x8004c598 : { *(.text.w3d_fn_8004c598) }
  .text.w3d_fn_8004c670 0x8004c670 : { *(.text.w3d_fn_8004c670) }
  .sdata 0x804ad378 (NOLOAD) : {
    . = 0x0; w3d_message_804ad378 = .;
    . = 0x8; w3d_message_804ad380 = .;
    . = 0x20; w3d_message_804ad398 = .;
    . = 0x28; w3d_message_804ad3a0 = .;
    . = 0x50; w3d_message_804ad3c8 = .;
    . = 0x78; w3d_message_804ad3f0 = .;
    . = 0x43dc; w3d_queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
