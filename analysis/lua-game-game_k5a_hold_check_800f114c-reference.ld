/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_hold_check_800f114c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800f12f0 = 0x800f12f0;
FUN_801613f0 = 0x801613f0;
s9_permute_80178dfc = 0x80178dfc;
w3d_cached_message_id = 0x8015f5a0;
w3d_empty_80342a74 = 0x80342a74;
w3d_f32_8038c2e0 = 0x8038c2e0;
w3d_message_post_current = 0x8016239c;
w3d_scene_timer_is_one_8006e71c = 0x8006e71c;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.k5a_hold_check_800f114c 0x800f114c : { *(.text.k5a_hold_check_800f114c) }
  .sdata 0x804af080 (NOLOAD) : {
    . = 0x0; w3d_message_804af080 = .;
    . = 0x26d4; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
