/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc28a_planner_release_record_80023010)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc28a_allocate_801613f0 = 0x801613f0;
cc28a_copy_802eee50 = 0x802eee50;
cc28a_format_803434d4 = 0x803434d4;
cc28a_id_8015f5a0 = 0x8015f5a0;
cc28a_post_8016239c = 0x8016239c;
cc28a_read_80178c48 = 0x80178c48;
cc28a_records_804200a4 = 0x804200a4;
cc28a_release_80209920 = 0x80209920;
cc28a_type_8040db38 = 0x8040db38;
cc28a_write_80178c54 = 0x80178c54;
SECTIONS {
  .text.cc28a_planner_release_record_80023010 0x80023010 : { *(.text.cc28a_planner_release_record_80023010) }
  .sdata 0x804aca40 (NOLOAD) : {
    . = 0x0; cc28a_heap_804aca40 = .;
    . = 0x8; cc28a_count_804aca48 = .;
    . = 0xc; cc28a_name_804aca4c = .;
    . = 0x4d14; cc28a_messages_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
