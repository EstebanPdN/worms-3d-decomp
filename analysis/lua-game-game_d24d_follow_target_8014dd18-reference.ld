/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_follow_target_8014dd18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_adjust_motion_800cfe68 = 0x800cfe68;
d24d_arena_alloc_801613f0 = 0x801613f0;
d24d_lookup_80164fc8 = 0x80164fc8;
d24d_message_id_8015f5a0 = 0x8015f5a0;
d24d_message_post_8016239c = 0x8016239c;
d24d_message_vtable_8040db38 = 0x8040db38;
d24d_mode_two_800cfc98 = 0x800cfc98;
SECTIONS {
  .text.d24d_follow_target_8014dd18 0x8014dd18 : { *(.text.d24d_follow_target_8014dd18) }
  .rodata 0x803a1688 : { *(.rodata) }
  .sdata 0x804afbf8 (NOLOAD) : {
    . = 0x0; d24d_message_key_804afbf8 = .;
    . = 0x1b5c; d24d_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
