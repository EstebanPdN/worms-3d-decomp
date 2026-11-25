/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31s_queue_dump_80165018)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__as__Q24_STLt6vector2Z15D31sQueueRecordZQ24_STLt9allocator1Z15D31sQueueRecordRCQ24_STLt6vector2Z15D31sQueueRecordZQ24_STLt9allocator1Z15D31sQueueRecord = 0x8034a85c;
append__15D31sQueueStringPCc = 0x8020bf2c;
category_format_803a4ad0 = 0x803a4ad0;
empty_string_804b06a0 = 0x804b06a0;
entry_format_803a4ae0 = 0x803a4ae0;
free = 0x802134fc;
pop_heap__H2ZP15D31sQueueRecordZ13D31sQueueLess_4_STLX01X01X11_v = 0x8034a7fc;
w3d_auto_801ffea8 = 0x801ffea8;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
w3d_string_release_header = 0x8020bb2c;
w3d_text_format_80343b0c = 0x80343b0c;
SECTIONS {
  .text.d31s_queue_dump_80165018 0x80165018 : { *(.text.d31s_queue_dump_80165018) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; queue_global_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
