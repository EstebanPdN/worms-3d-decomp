/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f16c_containers_cleanup_801632ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__dl__13F16cContainerPv = 0x801fe1f8;
__dl__19F16cContainerBufferPv = 0x801fe1f8;
arena_801613b8 = 0x801613b8;
arrayfree_801fe240 = 0x801fe240;
close_80210abc = 0x80210abc;
defer_80210afc = 0x80210afc;
holder_8034aef4 = 0x8034aef4;
prepare_80164f88 = 0x80164f88;
SECTIONS {
  .text.f16c_containers_cleanup_801632ac 0x801632ac : { *(.text.f16c_containers_cleanup_801632ac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
