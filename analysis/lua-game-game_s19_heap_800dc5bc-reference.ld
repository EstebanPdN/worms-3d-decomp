/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_heap_try_allocate_800dc5bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80209a20 = 0x80209a20;
w3d_heap_allocate = 0x802098d8;
SECTIONS {
  .text.s19_heap_try_allocate_800dc5bc 0x800dc5bc : { *(.text.s19_heap_try_allocate_800dc5bc) }
  .sdata 0x804aecac (NOLOAD) : {
    . = 0x0; lbl_804aecac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
