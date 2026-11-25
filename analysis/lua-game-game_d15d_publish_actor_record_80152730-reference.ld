/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d15d_actor_publish_record_80152730)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._10D15dRecord = 0x80118200;
__10D15dRecordRC10D15dRecord = 0x8034736c;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_actor_reset_construction_words = 0x8015286c;
w3d_auto_80131b50 = 0x80131b50;
w3d_cached_message_id = 0x8015f5a0;
w3d_engine_get_context = 0x80165254;
w3d_message_post_current = 0x8016239c;
w3d_message_type_8040db38 = 0x8040db38;
w3d_record_8042ff68 = 0x8042ff68;
SECTIONS {
  .text.d15d_actor_publish_record_80152730 0x80152730 : { *(.text.d15d_actor_publish_record_80152730) }
  .sdata 0x804aaae8 (NOLOAD) : {
    . = 0x0; w3d_flag_804aaae8 = .;
    . = 0x5314; w3d_cached_804afdfc = .;
    . = 0x6c6c; w3d_global_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
