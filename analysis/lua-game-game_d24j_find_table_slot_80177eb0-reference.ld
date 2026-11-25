/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24j_find_table_slot_80177eb0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80177e04 = 0x80177e04;
fn_80177e28 = 0x80177e28;
strcmp = 0x802ef234;
SECTIONS {
  .text.d24j_find_table_slot_80177eb0 0x80177eb0 : { *(.text.d24j_find_table_slot_80177eb0) }
  .sdata 0x804ab5ac (NOLOAD) : {
    . = 0x0; collisions_804ab5ac = .;
    . = 0x8; longest_804ab5b4 = .;
    . = 0xc; total_804ab5b8 = .;
    . = 0x10; hits_804ab5bc = .;
    . = 0x14; misses_804ab5c0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
