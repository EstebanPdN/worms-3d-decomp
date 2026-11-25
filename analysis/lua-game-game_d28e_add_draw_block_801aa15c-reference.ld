/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28e_add_draw_block_801aa15c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
free_802134fc = 0x802134fc;
lbl_80363bf4 = 0x80363bf4;
memcpy_802eee50 = 0x802eee50;
memmove_802eeef4 = 0x802eeef4;
w3d_ctor_801bddf0 = 0x801bddf0;
w3d_cx10b_arena_allocate_existing_80209d50 = 0x80209d50;
w3d_handle_storage_fallback_803413d8 = 0x803413d8;
w3d_heap_allocate_801fe1d8 = 0x801fe1d8;
SECTIONS {
  .text.w3d_d28e_add_draw_block_801aa15c 0x801aa15c : { *(.text.w3d_d28e_add_draw_block_801aa15c) }
  .rodata 0x803aa0f4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
