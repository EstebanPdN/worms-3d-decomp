/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_scene_start_801599ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_acquire_message_80162024 = 0x80162024;
d24d_arena_alloc_801613f0 = 0x801613f0;
d24d_message_id_8015f5a0 = 0x8015f5a0;
d24d_message_post_8016239c = 0x8016239c;
d24d_message_vtable_8040db38 = 0x8040db38;
d24d_value_message_800c1620 = 0x800c1620;
SECTIONS {
  .text.d24d_scene_start_801599ec 0x801599ec : { *(.text.d24d_scene_start_801599ec) }
  .sdata 0x804ab40c (NOLOAD) : {
    . = 0x0; d24d_flag_804ab40c = .;
    . = 0x4b7c; d24d_key_804aff88 = .;
    . = 0x4b84; d24d_key_804aff90 = .;
    . = 0x4b94; d24d_key_804affa0 = .;
    . = 0x4b9c; d24d_key_804affa8 = .;
    . = 0x4ba4; d24d_key_804affb0 = .;
    . = 0x4bac; d24d_key_804affb8 = .;
    . = 0x4bc4; d24d_key_804affd0 = .;
    . = 0x4bcc; d24d_key_804affd8 = .;
    . = 0x4bd4; d24d_key_804affe0 = .;
    . = 0x4bdc; d24d_key_804affe8 = .;
    . = 0x4bfc; d24d_key_804b0008 = .;
    . = 0x4c04; d24d_key_804b0010 = .;
    . = 0x6348; d24d_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
