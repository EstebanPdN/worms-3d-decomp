/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24h_pool_add_800c53a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802eee50 = 0x802eee50;
lbl_803f5718 = 0x803f5718;
lbl_8043e438 = 0x8043e438;
lbl_8043e448 = 0x8043e448;
lbl_804a85d8 = 0x804a85d8;
lbl_804a87d8 = 0x804a87d8;
w3d_auto_803446e0 = 0x803446e0;
w3d_d24h_order_insert_800c54d0 = 0x800c54d0;
w3d_empty_800f74cc = 0x800f74cc;
w3d_heap_allocate = 0x802098d8;
w3d_set_800f7500 = 0x800f7500;
w3d_set_800f7510 = 0x800f7510;
w3d_set_800f7520 = 0x800f7520;
SECTIONS {
  .text.w3d_d24h_pool_add_800c53a0 0x800c53a0 : { *(.text.w3d_d24h_pool_add_800c53a0) }
  .sdata 0x804af100 (NOLOAD) : {
    . = 0x0; lbl_804af100 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
