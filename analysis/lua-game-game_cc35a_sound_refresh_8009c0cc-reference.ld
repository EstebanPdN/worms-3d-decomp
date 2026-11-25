/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc35a_sound_refresh_8009c0cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc35a_alloc_801613f0 = 0x801613f0;
cc35a_config_801797b4 = 0x801797b4;
cc35a_context_80341584 = 0x80341584;
cc35a_id_8015f5a0 = 0x8015f5a0;
cc35a_owner_8009c850 = 0x8009c850;
cc35a_post_8016239c = 0x8016239c;
cc35a_release_800e5bb8 = 0x800e5bb8;
cc35a_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.cc35a_sound_refresh_8009c0cc 0x8009c0cc : { *(.text.cc35a_sound_refresh_8009c0cc) }
  .sdata 0x804ae068 (NOLOAD) : {
    . = 0x0; cc35a_cache_804ae068 = .;
    . = 0x36ec; cc35a_arena_804b1754 = .;
    . = 0x3720; cc35a_service_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
