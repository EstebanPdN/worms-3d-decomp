/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30j_insert_pool_item_8017c464)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcmp = 0x802ef234;
w3d_k1d_hash_name_8017e1c4 = 0x8017e1c4;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.d30j_insert_pool_item_8017c464 0x8017c464 : { *(.text.d30j_insert_pool_item_8017c464) }
  .sdata 0x804ab5e4 (NOLOAD) : {
    . = 0x0; lbl_804ab5e4 = .;
    . = 0x8; lbl_804ab5ec = .;
    . = 0xc; lbl_804ab5f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
