/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_turns_rebuild_80157afc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._17d24d_HandleMember = 0x80126230;
__17d24d_HandleMember = 0x80126184;
d24d_member_set_field_801262c0 = 0x801262c0;
d24d_member_set_float_8012629c = 0x8012629c;
d24d_member_set_slot_801262e4 = 0x801262e4;
d24d_member_set_word_8012632c = 0x8012632c;
d24d_storage_release_802134fc = 0x802134fc;
d24d_turns_gather_80158358 = 0x80158358;
d24d_turns_process_80157c58 = 0x80157c58;
d24d_worm_info_800fc6dc = 0x800fc6dc;
memcpy = 0x802eee50;
SECTIONS {
  .text.d24d_turns_rebuild_80157afc 0x80157afc : { *(.text.d24d_turns_rebuild_80157afc) }
  .rodata 0x803a2c38 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
