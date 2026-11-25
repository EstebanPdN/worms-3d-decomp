/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b2_select_800e2368)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b2_config_801797b4 = 0x801797b4;
sol35b2_property_80189518 = 0x80189518;
sol35b2_sync_80341584 = 0x80341584;
SECTIONS {
  .text.sol35b2_select_800e2368 0x800e2368 : { *(.text.sol35b2_select_800e2368) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
