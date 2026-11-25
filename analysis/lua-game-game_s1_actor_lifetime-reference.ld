/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80049804)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_destroy = 0x80161050;
w3d_actor_handle_member_destroy = 0x80126230;
w3d_cached_message_id = 0x8015f5a0;
w3d_fn_801190b4 = 0x801190b4;
w3d_fn_801613f0 = 0x801613f0;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_vtable_8040e9b8 = 0x8040e9b8;
SECTIONS {
  .text.w3d_fn_80049804 0x80049804 : { *(.text.w3d_fn_80049804) }
  .text.w3d_fn_8004a38c 0x8004a38c : { *(.text.w3d_fn_8004a38c) }
  .text.w3d_fn_8004a930 0x8004a930 : { *(.text.w3d_fn_8004a930) }
  .sdata 0x804ad348 (NOLOAD) : {
    . = 0x0; w3d_id_804ad348 = .;
    . = 0x20; w3d_id_804ad368 = .;
    . = 0x440c; w3d_queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
