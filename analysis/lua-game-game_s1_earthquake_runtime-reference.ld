/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_800619e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_auto_80161080 = 0x80161080;
w3d_auto_801797b4 = 0x801797b4;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80341584 = 0x80341584;
w3d_engine_get_context = 0x80165254;
w3d_fn_8002ad9c = 0x8002ad9c;
w3d_fn_800c56b8 = 0x800c56b8;
w3d_fn_800fc43c = 0x800fc43c;
w3d_fn_800fde64 = 0x800fde64;
w3d_fn_801613f0 = 0x801613f0;
w3d_int_message_init_80125fdc = 0x80125fdc;
w3d_message_post_current = 0x8016239c;
w3d_scene_timer_is_one_8006e71c = 0x8006e71c;
w3d_str_80379394 = 0x80379394;
w3d_str_803795c0 = 0x803795c0;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_fn_800619e4 0x800619e4 : { *(.text.w3d_fn_800619e4) }
  .text.w3d_fn_80061cd4 0x80061cd4 : { *(.text.w3d_fn_80061cd4) }
  .text.w3d_fn_80062228 0x80062228 : { *(.text.w3d_fn_80062228) }
  .text.w3d_fn_800622bc 0x800622bc : { *(.text.w3d_fn_800622bc) }
  .sdata 0x804ad4ec (NOLOAD) : {
    . = 0x0; w3d_message_804ad4ec = .;
    . = 0x18; w3d_message_804ad504 = .;
    . = 0x2c; w3d_message_804ad518 = .;
    . = 0x34; w3d_message_804ad520 = .;
    . = 0x4268; w3d_queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
