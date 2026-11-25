/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8004cd08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_auto_80178df0 = 0x80178df0;
w3d_cached_message_id = 0x8015f5a0;
w3d_f32_8037741c = 0x8037741c;
w3d_f32_80377420 = 0x80377420;
w3d_fn_800e5ca4 = 0x800e5ca4;
w3d_fn_800fc1f0 = 0x800fc1f0;
w3d_fn_800fc3b0 = 0x800fc3b0;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_fn_800fc82c = 0x800fc82c;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80178474 = 0x80178474;
w3d_message_post_current = 0x8016239c;
w3d_message_vtable_8040db38 = 0x8040db38;
w3d_str_80377118 = 0x80377118;
w3d_str_803772bc = 0x803772bc;
w3d_str_803773f0 = 0x803773f0;
w3d_str_80377404 = 0x80377404;
w3d_str_8037740c = 0x8037740c;
SECTIONS {
  .text.w3d_fn_8004cd08 0x8004cd08 : { *(.text.w3d_fn_8004cd08) }
  .text.w3d_fn_8004d10c 0x8004d10c : { *(.text.w3d_fn_8004d10c) }
  .text.w3d_fn_8004d35c 0x8004d35c : { *(.text.w3d_fn_8004d35c) }
  .text.w3d_fn_8004d54c 0x8004d54c : { *(.text.w3d_fn_8004d54c) }
  .sdata 0x804ad350 (NOLOAD) : {
    . = 0x0; w3d_message_804ad350 = .;
    . = 0xa8; w3d_message_804ad3f8 = .;
    . = 0x4404; w3d_queue_804b1754 = .;
    . = 0x4438; w3d_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
