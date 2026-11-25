/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(Insert__15D32kStringTableRC7D32kStrUs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
free = 0x802134fc;
malloc = 0x80212fd4;
strcmp = 0x802ef234;
SECTIONS {
  .text.Insert__15D32kStringTableRC7D32kStrUs 0x8020cc90 : { *(.text.Insert__15D32kStringTableRC7D32kStrUs) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
