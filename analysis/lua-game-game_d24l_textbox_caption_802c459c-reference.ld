/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_textbox_caption_802c459c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802c38cc = 0x802c38cc;
fn_802c4744 = 0x802c4744;
lbl_803d86a4 = 0x803d86a4;
lbl_803d8758 = 0x803d8758;
w3d_as_80343744 = 0x80343744;
w3d_as_node_80343580 = 0x80343580;
w3d_int_8020c5cc = 0x8020c5cc;
w3d_lookup_800fc1b0 = 0x800fc1b0;
w3d_set_name_view_8015adf4 = 0x8015adf4;
w3d_string_assign_8020bd38 = 0x8020bd38;
w3d_string_format_8020c510 = 0x8020c510;
w3d_text_80179170 = 0x80179170;
SECTIONS {
  .text.d24l_textbox_caption_802c459c 0x802c459c : { *(.text.d24l_textbox_caption_802c459c) }
  .rodata 0x803d875c : { *(.rodata) }
  .sdata 0x804abb60 (NOLOAD) : {
    . = 0x0; w3d_resource_base_804abb60 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
