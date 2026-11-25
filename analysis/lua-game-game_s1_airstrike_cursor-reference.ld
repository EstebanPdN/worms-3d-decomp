/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8004dc38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178d1c = 0x80178d1c;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_native_cast = 0x80342a78;
w3d_empty_80341348 = 0x80341348;
w3d_engine_get_context = 0x80165254;
w3d_fn_8015ae3c = 0x8015ae3c;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80173df0 = 0x80173df0;
w3d_fn_8017fc90 = 0x8017fc90;
w3d_message_post_current = 0x8016239c;
w3d_message_vtable_8040db38 = 0x8040db38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
w3d_vtable_8040e9f8 = 0x8040e9f8;
SECTIONS {
  .text.w3d_fn_8004dc38 0x8004dc38 : { *(.text.w3d_fn_8004dc38) }
  .text.w3d_fn_8004e004 0x8004e004 : { *(.text.w3d_fn_8004e004) }
  .text.w3d_fn_8004e2a4 0x8004e2a4 : { *(.text.w3d_fn_8004e2a4) }
  .text.w3d_fn_8004e324 0x8004e324 : { *(.text.w3d_fn_8004e324) }
  .text.w3d_fn_8004e384 0x8004e384 : { *(.text.w3d_fn_8004e384) }
  .text.w3d_fn_8004e544 0x8004e544 : { *(.text.w3d_fn_8004e544) }
  .sdata 0x804abab4 (NOLOAD) : {
    . = 0x0; w3d_disabled_804abab4 = .;
    . = 0x1978; w3d_message_804ad42c = .;
    . = 0x1980; w3d_message_804ad434 = .;
    . = 0x1998; w3d_message_804ad44c = .;
    . = 0x19a0; w3d_color_804ad454 = .;
    . = 0x19a4; w3d_color_804ad458 = .;
    . = 0x19a8; w3d_color_804ad45c = .;
    . = 0x5ca0; w3d_queue_804b1754 = .;
    . = 0x5cd4; w3d_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
