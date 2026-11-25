/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25l_custom_frame_create_802ba710)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__19D25lString_803426b8 = 0x803426b8;
fn_802baf1c = 0x802baf1c;
lbl_8045e788 = 0x8045e788;
s11_named_handle_802badf0 = 0x802badf0;
w3d_call_with_owner_802bbcc4 = 0x802bbcc4;
w3d_forward_to_held_802bbc90 = 0x802bbc90;
w3d_heap_allocate_entry_801fe1d8 = 0x801fe1d8;
w3d_string_base_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d25l_custom_frame_create_802ba710 0x802ba710 : { *(.text.d25l_custom_frame_create_802ba710) }
  .rodata 0x803d820c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
