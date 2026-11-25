/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b2_release_800ffbe0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b2_backend_release_801fe288 = 0x801fe288;
sol35b2_copy_802eee50 = 0x802eee50;
sol35b2_task_destroy_800ffb28 = 0x800ffb28;
SECTIONS {
  .text.sol35b2_release_800ffbe0 0x800ffbe0 : { *(.text.sol35b2_release_800ffbe0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
