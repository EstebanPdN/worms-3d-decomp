/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_scene_message_80159698)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__11d24d_StringPCc = 0x8020bb54;
d24d_arena_alloc_801613f0 = 0x801613f0;
d24d_kind_message_80125fdc = 0x80125fdc;
d24d_message_id_8015f5a0 = 0x8015f5a0;
d24d_message_is_8015f65c = 0x8015f65c;
d24d_message_post_8016239c = 0x8016239c;
d24d_message_text_8010a8fc = 0x8010a8fc;
d24d_message_vtable_8040db38 = 0x8040db38;
d24d_scene_base_8015fb34 = 0x8015fb34;
d24d_scene_reset_80159978 = 0x80159978;
d24d_scene_start_801599ec = 0x801599ec;
d24d_scene_stop_80159c24 = 0x80159c24;
d24d_string_finish_8020c5c4 = 0x8020c5c4;
d24d_string_release_80341588 = 0x80341588;
d24d_text_803a3fe4 = 0x803a3fe4;
strcmp = 0x802ef234;
SECTIONS {
  .text.d24d_scene_message_80159698 0x80159698 : { *(.text.d24d_scene_message_80159698) }
  .sdata 0x804aff88 (NOLOAD) : {
    . = 0x0; d24d_key_804aff88 = .;
    . = 0x8; d24d_key_804aff90 = .;
    . = 0x10; d24d_key_804aff98 = .;
    . = 0x18; d24d_key_804affa0 = .;
    . = 0x20; d24d_key_804affa8 = .;
    . = 0x28; d24d_key_804affb0 = .;
    . = 0x30; d24d_key_804affb8 = .;
    . = 0x48; d24d_key_804affd0 = .;
    . = 0x50; d24d_key_804affd8 = .;
    . = 0x58; d24d_key_804affe0 = .;
    . = 0x60; d24d_key_804affe8 = .;
    . = 0x70; d24d_key_804afff8 = .;
    . = 0x78; d24d_key_804b0000 = .;
    . = 0x80; d24d_key_804b0008 = .;
    . = 0x88; d24d_key_804b0010 = .;
    . = 0x17cc; d24d_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
