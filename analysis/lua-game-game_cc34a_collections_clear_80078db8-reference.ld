/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc34a_collections_clear_80078db8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc34a_clear_801f2798 = 0x801f2798;
cc34a_copy_802eee50 = 0x802eee50;
cc34a_free_80209920 = 0x80209920;
SECTIONS {
  .text.cc34a_collections_clear_80078db8 0x80078db8 : { *(.text.cc34a_collections_clear_80078db8) }
  .sdata 0x804adde4 (NOLOAD) : {
    . = 0x0; cc34a_heap_804adde4 = .;
    . = 0x3a10; cc34a_global_804b17f4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
