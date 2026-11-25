/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_r23a_default_pair_8005200c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_destroy_8020fc60 = 0x8020fc60;
concatenate_802ce920 = 0x802ce920;
const_error_text_803a9a28 = 0x803a9a28;
constant_8037821c = 0x8037821c;
construct_shared_8017990c = 0x8017990c;
pair_sink_80052044 = 0x80052044;
push_string_802cdfd4 = 0x802cdfd4;
raise_error_802ce89c = 0x802ce89c;
table_80411728 = 0x80411728;
table_80411750 = 0x80411750;
table_80411868 = 0x80411868;
table_80411890 = 0x80411890;
table_80412e20 = 0x80412e20;
SECTIONS {
  .text.w3d_r23a_default_pair_8005200c 0x8005200c : { *(.text.w3d_r23a_default_pair_8005200c) }
  .text.w3d_r23a_query_flag_800dfd48 0x800dfd48 : { *(.text.w3d_r23a_query_flag_800dfd48) }
  .text.w3d_r23a_dual_teardown_801611a4 0x801611a4 : { *(.text.w3d_r23a_dual_teardown_801611a4) }
  .text.w3d_r23a_dual_teardown_80162a40 0x80162a40 : { *(.text.w3d_r23a_dual_teardown_80162a40) }
  .text.w3d_r23a_shared_node_construct_80188a68 0x80188a68 : { *(.text.w3d_r23a_shared_node_construct_80188a68) }
  .text.w3d_r23a_const_member_error_8019f8f0 0x8019f8f0 : { *(.text.w3d_r23a_const_member_error_8019f8f0) }
  .sdata 0x804ab69c (NOLOAD) : {
    . = 0x0; shared_count_804ab69c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
