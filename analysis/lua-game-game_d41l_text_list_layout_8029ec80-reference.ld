/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d41l_text_list_layout_8029ec80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__4Text = 0x803426b8;
__4TextPCc = 0x8020bb54;
__builtin_new = 0x801fe1d8;
buffer_80470930 = 0x80470930;
d24l_text_list_lines_8029f598 = 0x8029f598;
d25l_expand_text_properties_8029eb3c = 0x8029eb3c;
d25l_text_list_scroll_box_b_802a047c = 0x802a047c;
fn_802a06ac = 0x802a06ac;
fn_802a0f98 = 0x802a0f98;
free = 0x802134fc;
k5_803d1dbc = 0x803d1dbc;
malloc = 0x80212fd4;
memmove = 0x802eeef4;
s9_permute_8018b4cc = 0x8018b4cc;
text_empty_803d0f78 = 0x803d0f78;
text_hyphen_803d1db8 = 0x803d1db8;
text_space_803d0f60 = 0x803d0f60;
tsonnet_c31_text_size_802b1880 = 0x802b1880;
w3d_cx9c_floorf_802e87d4 = 0x802e87d4;
w3d_empty_802a0c44 = 0x802a0c44;
w3d_empty_8034435c = 0x8034435c;
w3d_runtime_service_lookup = 0x8015ae3c;
w3d_s4_text_list_remove_box = 0x802a0664;
w3d_string_append = 0x8020bf2c;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d41l_text_list_layout_8029ec80 0x8029ec80 : { *(.text.d41l_text_list_layout_8029ec80) }
  .rodata 0x803d1dc0 : { *(.rodata) }
  .sdata 0x804b0e6c (NOLOAD) : {
    . = 0x0; lbl_804b0e6c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
