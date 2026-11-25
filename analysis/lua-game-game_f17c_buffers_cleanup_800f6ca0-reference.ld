/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f17c_cleanup_800f6ca0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
copy_802eee50 = 0x802eee50;
free_802134fc = 0x802134fc;
release_80209920 = 0x80209920;
SECTIONS {
  .text.f17c_cleanup_800f6ca0 0x800f6ca0 : { *(.text.f17c_cleanup_800f6ca0) }
  .sdata 0x804adde4 (NOLOAD) : {
    . = 0x0; heap_804adde4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
