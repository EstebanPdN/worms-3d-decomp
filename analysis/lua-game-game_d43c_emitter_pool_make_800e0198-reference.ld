/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d43c_emitter_pool_make_800e0198)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__2PA = 0x800dc634;
__2PB = 0x800e6738;
__2PC = 0x800de6c4;
alloc_800dc5bc = 0x800dc5bc;
alloc_800de8d8 = 0x800de8d8;
heap_free_80209a20 = 0x80209a20;
release_800e0400 = 0x800e0400;
vtA_8040ff48 = 0x8040ff48;
vtB_8040ff28 = 0x8040ff28;
vtC_8040ff08 = 0x8040ff08;
SECTIONS {
  .text.d43c_emitter_pool_make_800e0198 0x800e0198 : { *(.text.d43c_emitter_pool_make_800e0198) }
  .sdata 0x804aecac (NOLOAD) : {
    . = 0x0; heap_804aecac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
