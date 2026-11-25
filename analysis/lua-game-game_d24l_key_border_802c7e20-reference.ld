/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_key_border_802c7e20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D24lStringPCc = 0x8020bb54;
fn_802c7f60 = 0x802c7f60;
w3d_as_mesh_8034357c = 0x8034357c;
w3d_handle_set_name_8015adf4 = 0x8015adf4;
w3d_s20_store_byte_value_80173f88 = 0x80173f88;
w3d_set_panel_vectors_802c7d24 = 0x802c7d24;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d24l_key_border_802c7e20 0x802c7e20 : { *(.text.d24l_key_border_802c7e20) }
  .rodata 0x803d8df0 : { *(.rodata) }
  .sdata 0x804abb60 (NOLOAD) : {
    . = 0x0; w3d_resource_base_804abb60 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
