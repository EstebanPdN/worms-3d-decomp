/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g3c_defer_free_80214894)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
callback_8040077c = 0x8040077c;
fn_80214718 = 0x80214718;
memset = 0x802eefe0;
SECTIONS {
  .text.g3c_defer_free_80214894 0x80214894 : { *(.text.g3c_defer_free_80214894) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
