/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_land_damage_add_8009d430)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_blast_800b92a4 = 0x800b92a4;
w3d_copy_802eee50 = 0x802eee50;
w3d_heap_allocate_802098d8 = 0x802098d8;
w3d_land_clear_801040d0 = 0x801040d0;
w3d_message_post_8016239c = 0x8016239c;
w3d_position_8043ae20 = 0x8043ae20;
w3d_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_d24b_land_damage_add_8009d430 0x8009d430 : { *(.text.w3d_d24b_land_damage_add_8009d430) }
  .rodata 0x803802a0 : { *(.rodata) }
  .sdata 0x804af5bc (NOLOAD) : {
    . = 0x0; w3d_pool_804af5bc = .;
    . = 0x2198; w3d_message_arena_804b1754 = .;
    . = 0x21ec; w3d_cell_x_804b17a8 = .;
    . = 0x21f0; w3d_cell_y_804b17ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
