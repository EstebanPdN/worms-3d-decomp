/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b2_clip_800e96d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b2_blend_8038b290 = 0x8038b290;
sol35b2_config_801797b4 = 0x801797b4;
sol35b2_duration_8017fc90 = 0x8017fc90;
sol35b2_empty_8038b1f8 = 0x8038b1f8;
sol35b2_identity_80341348 = 0x80341348;
sol35b2_play_80181640 = 0x80181640;
sol35b2_rate_cap_8038b28c = 0x8038b28c;
sol35b2_rate_scale_8038b288 = 0x8038b288;
sol35b2_service_8015ae3c = 0x8015ae3c;
sol35b2_sync_80341584 = 0x80341584;
SECTIONS {
  .text.sol35b2_clip_800e96d8 0x800e96d8 : { *(.text.sol35b2_clip_800e96d8) }
  .rodata 0x8038b280 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
