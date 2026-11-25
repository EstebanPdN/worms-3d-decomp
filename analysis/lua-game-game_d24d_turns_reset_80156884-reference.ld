/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_turns_reset_80156884)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_display_803426b4 = 0x803426b4;
d24d_display_update_80178c54 = 0x80178c54;
d24d_storage_allocate_80212fd4 = 0x80212fd4;
d24d_storage_release_802134fc = 0x802134fc;
d24d_turns_apply_scene_80158810 = 0x80158810;
d24d_turns_begin_80156214 = 0x80156214;
d24d_turns_create_actor_80156ac4 = 0x80156ac4;
d24d_turns_rebuild_80157afc = 0x80157afc;
d24d_worm_info_800fc6dc = 0x800fc6dc;
memcpy = 0x802eee50;
SECTIONS {
  .text.d24d_turns_reset_80156884 0x80156884 : { *(.text.d24d_turns_reset_80156884) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
