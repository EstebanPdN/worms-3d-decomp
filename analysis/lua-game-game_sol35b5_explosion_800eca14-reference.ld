/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b5_explosion_800eca14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b5_allocate_801613f0 = 0x801613f0;
sol35b5_config_801797b4 = 0x801797b4;
sol35b5_construct_800666b4 = 0x800666b4;
sol35b5_post_8016239c = 0x8016239c;
sol35b5_random_80161080 = 0x80161080;
sol35b5_sync_80341584 = 0x80341584;
SECTIONS {
  .text.sol35b5_explosion_800eca14 0x800eca14 : { *(.text.sol35b5_explosion_800eca14) }
  .rodata 0x8038b5a0 : { *(.rodata) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; sol35b5_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
