/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b9_retreat_setup_800ee720)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b9_retreat_allocate_801613f0 = 0x801613f0;
sol35b9_retreat_config_801797b4 = 0x801797b4;
sol35b9_retreat_construct_801190b4 = 0x801190b4;
sol35b9_retreat_id_8015f5a0 = 0x8015f5a0;
sol35b9_retreat_post_8016239c = 0x8016239c;
sol35b9_retreat_read_800fc1f0 = 0x800fc1f0;
sol35b9_retreat_register_80164514 = 0x80164514;
sol35b9_retreat_service_8020b680 = 0x8020b680;
sol35b9_retreat_sync_80341584 = 0x80341584;
sol35b9_retreat_task_8040def8 = 0x8040def8;
sol35b9_retreat_task_8040df38 = 0x8040df38;
sol35b9_retreat_task_80410318 = 0x80410318;
sol35b9_retreat_text_8038bd7c = 0x8038bd7c;
sol35b9_retreat_text_8038bd90 = 0x8038bd90;
sol35b9_retreat_type_8040db38 = 0x8040db38;
sol35b9_retreat_write_800fc3b0 = 0x800fc3b0;
SECTIONS {
  .text.sol35b9_retreat_setup_800ee720 0x800ee720 : { *(.text.sol35b9_retreat_setup_800ee720) }
  .sdata 0x804aef8c (NOLOAD) : {
    . = 0x0; sol35b9_retreat_cache_804aef8c = .;
    . = 0x8; sol35b9_retreat_cache_804aef94 = .;
    . = 0x10; sol35b9_retreat_cache_804aef9c = .;
    . = 0x18; sol35b9_retreat_cache_804aefa4 = .;
    . = 0x27c8; sol35b9_retreat_arena_804b1754 = .;
    . = 0x2800; sol35b9_retreat_registry_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
