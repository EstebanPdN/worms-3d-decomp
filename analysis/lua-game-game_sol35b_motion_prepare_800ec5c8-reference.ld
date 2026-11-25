/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b_motion_prepare_800ec5c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b_allocate_801613f0 = 0x801613f0;
sol35b_apply_800ed9c8 = 0x800ed9c8;
sol35b_config_801797b4 = 0x801797b4;
sol35b_message_id_8015f5a0 = 0x8015f5a0;
sol35b_prepare_800ec400 = 0x800ec400;
sol35b_publish_8015fc58 = 0x8015fc58;
sol35b_reset_800eb6e4 = 0x800eb6e4;
sol35b_speed_800ecf54 = 0x800ecf54;
sol35b_sync_80341584 = 0x80341584;
sol35b_threshold_8038b564 = 0x8038b564;
sol35b_type_8040db38 = 0x8040db38;
SECTIONS {
  .text.sol35b_motion_prepare_800ec5c8 0x800ec5c8 : { *(.text.sol35b_motion_prepare_800ec5c8) }
  .sdata 0x804aef10 (NOLOAD) : {
    . = 0x0; sol35b_cached_id_804aef10 = .;
    . = 0x2844; sol35b_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
