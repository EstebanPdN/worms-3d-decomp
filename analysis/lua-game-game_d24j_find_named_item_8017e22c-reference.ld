/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24j_find_named_item_8017e22c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8017e1a0 = 0x8017e1a0;
fn_8017e1c4 = 0x8017e1c4;
strcmp = 0x802ef234;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d24j_find_named_item_8017e22c 0x8017e22c : { *(.text.d24j_find_named_item_8017e22c) }
  .sdata 0x804ab5e4 (NOLOAD) : {
    . = 0x0; collisions_804ab5e4 = .;
    . = 0x8; longest_804ab5ec = .;
    . = 0xc; total_804ab5f0 = .;
    . = 0x10; hits_804ab5f4 = .;
    . = 0x14; misses_804ab5f8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
