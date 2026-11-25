/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc34a_actor_range_warning_80070e94)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc34a_alloc_801613f0 = 0x801613f0;
cc34a_config_801797b4 = 0x801797b4;
cc34a_context_80341584 = 0x80341584;
cc34a_id_8015f5a0 = 0x8015f5a0;
cc34a_init_80125fdc = 0x80125fdc;
cc34a_post_8016239c = 0x8016239c;
cc34a_send_8015fc58 = 0x8015fc58;
cc34a_settext_801790bc = 0x801790bc;
cc34a_string_8037ca48 = 0x8037ca48;
cc34a_text_80343744 = 0x80343744;
cc34a_type_8040db38 = 0x8040db38;
SECTIONS {
  .text.cc34a_actor_range_warning_80070e94 0x80070e94 : { *(.text.cc34a_actor_range_warning_80070e94) }
  .rodata 0x8037ca58 : { *(.rodata) }
  .sdata 0x804aafac (NOLOAD) : {
    . = 0x0; cc34a_limit_804aafac = .;
    . = 0x2998; cc34a_cache_804ad944 = .;
    . = 0x29a0; cc34a_cache_804ad94c = .;
    . = 0x67a8; cc34a_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
