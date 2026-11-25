/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_turns_add_worm_80156b24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_actor_id_80410ef0 = 0x80410ef0;
d24d_create_actor_8020b680 = 0x8020b680;
d24d_register_actor_80164514 = 0x80164514;
d24d_storage_allocate_80212fd4 = 0x80212fd4;
d24d_storage_release_802134fc = 0x802134fc;
d24d_team_record_800fc7f8 = 0x800fc7f8;
d24d_turns_apply_scene_80158810 = 0x80158810;
d24d_turns_gather_80158358 = 0x80158358;
d24d_turns_process_80157c58 = 0x80157c58;
d24d_worm_info_800fc6dc = 0x800fc6dc;
memcpy = 0x802eee50;
SECTIONS {
  .text.d24d_turns_add_worm_80156b24 0x80156b24 : { *(.text.d24d_turns_add_worm_80156b24) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; d24d_registry_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
