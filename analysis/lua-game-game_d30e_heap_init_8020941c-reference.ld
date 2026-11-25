/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30e_heap_init_8020941c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80209190 = 0x80209190;
lbl_803b2f28 = 0x803b2f28;
lbl_803b2f3c = 0x803b2f3c;
lbl_803b2f60 = 0x803b2f60;
lbl_803b2f7c = 0x803b2f7c;
printf = 0x802ebfbc;
w3d_aligned_allocate = 0x801fe2a8;
w3d_d28k_heap_open_802168c4 = 0x802168c4;
w3d_empty_802092c0 = 0x802092c0;
w3d_empty_802092c4 = 0x802092c4;
w3d_empty_802095d4 = 0x802095d4;
w3d_heap_morecore = 0x801fdfc8;
SECTIONS {
  .text.w3d_d30e_heap_init_8020941c 0x8020941c : { *(.text.w3d_d30e_heap_init_8020941c) }
  .sdata 0x804aba74 (NOLOAD) : {
    . = 0x0; lbl_804aba74 = .;
    . = 0x8; lbl_804aba7c = .;
    . = 0x10; lbl_804aba84 = .;
    . = 0x14; lbl_804aba88 = .;
    . = 0x4bfc; lbl_804b0670 = .;
    . = 0x4c10; lbl_804b0684 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
