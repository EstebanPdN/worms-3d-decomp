/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol30b_allocate_arena_802167a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
hooks_80400768 = 0x80400768;
setup_80215c58 = 0x80215c58;
SECTIONS {
  .text.sol30b_allocate_arena_802167a0 0x802167a0 : { *(.text.sol30b_allocate_arena_802167a0) }
  .sdata 0x804aba74 (NOLOAD) : {
    . = 0x0; dispatch_804aba74 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
