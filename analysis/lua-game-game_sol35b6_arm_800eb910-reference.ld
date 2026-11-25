/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b6_arm_800eb910)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b6_allocate_801613f0 = 0x801613f0;
sol35b6_config_801797b4 = 0x801797b4;
sol35b6_construct_80125fdc = 0x80125fdc;
sol35b6_file_8038b4c4 = 0x8038b4c4;
sol35b6_id_8015f5a0 = 0x8015f5a0;
sol35b6_log_80022e20 = 0x80022e20;
sol35b6_publish_8015fc58 = 0x8015fc58;
sol35b6_sync_80341584 = 0x80341584;
sol35b6_text_8038b4e4 = 0x8038b4e4;
sol35b6_type_80361860 = 0x80361860;
sol35b6_type_803618f0 = 0x803618f0;
SECTIONS {
  .text.sol35b6_arm_800eb910 0x800eb910 : { *(.text.sol35b6_arm_800eb910) }
  .sdata 0x804aef00 (NOLOAD) : {
    . = 0x0; sol35b6_cache_804aef00 = .;
    . = 0x2854; sol35b6_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
