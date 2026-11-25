/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f2b_dispatch_snapshot_801623dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_801fe0b8 = 0x801fe0b8;
copy_802eee50 = 0x802eee50;
dispatch_8015fc38 = 0x8015fc38;
release_801fe160 = 0x801fe160;
SECTIONS {
  .text.f2b_dispatch_snapshot_801623dc 0x801623dc : { *(.text.f2b_dispatch_snapshot_801623dc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
