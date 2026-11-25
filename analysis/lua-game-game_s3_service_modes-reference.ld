/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_choose_worm_construct)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_initialize = 0x80161014;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_cached_message_id = 0x8015f5a0;
w3d_fn_80020834 = 0x80020834;
w3d_fn_800fc43c = 0x800fc43c;
w3d_fn_801613f0 = 0x801613f0;
w3d_heap_release = 0x80209920;
w3d_message_post_current = 0x8016239c;
w3d_str_803a3fd0 = 0x803a3fd0;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_type_8040db38 = 0x8040db38;
w3d_vtable_80410f80 = 0x80410f80;
w3d_vtable_80410ff0 = 0x80410ff0;
SECTIONS {
  .text.w3d_choose_worm_construct 0x801594bc : { *(.text.w3d_choose_worm_construct) }
  .text.w3d_choose_worm_finish 0x80159978 : { *(.text.w3d_choose_worm_finish) }
  .text.w3d_service_mode_destroy 0x8015a39c : { *(.text.w3d_service_mode_destroy) }
  .text.w3d_service_mode_virtual_query 0x8015a6b8 : { *(.text.w3d_service_mode_virtual_query) }
  .text.w3d_service_mode_is_inactive 0x8015ab1c : { *(.text.w3d_service_mode_is_inactive) }
  .text.w3d_service_optional_context_query 0x8015abcc : { *(.text.w3d_service_optional_context_query) }
  .sdata 0x804ab40c (NOLOAD) : {
    . = 0x0; w3d_flag_804ab40c = .;
    . = 0x4bbc; w3d_cache_804affc8 = .;
    . = 0x4c38; w3d_heap_804b0044 = .;
    . = 0x6348; w3d_global_804b1754 = .;
    . = 0x6354; w3d_global_804b1760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
