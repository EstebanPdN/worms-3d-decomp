/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d20f_list_element_802b8be0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__15D20fListElement = 0x802bce10;
__nw__15D20fListElementUi = 0x801fe1d8;
d20f_element_height_802bfb68 = 0x802bfb68;
d20f_element_interface_802bdc88 = 0x802bdc88;
d20f_element_interface_802c0c24 = 0x802c0c24;
d20f_element_layer_802c0cac = 0x802c0cac;
d20f_element_length_802bd3cc = 0x802bd3cc;
d20f_element_position_802bd430 = 0x802bd430;
d20f_element_property_802bfba4 = 0x802bfba4;
d20f_element_select_802bd2c4 = 0x802bd2c4;
d20f_element_setup_802bd158 = 0x802bd158;
d20f_element_value_802bfb2c = 0x802bfb2c;
d20f_text_size_802b1880 = 0x802b1880;
SECTIONS {
  .text.d20f_list_element_802b8be0 0x802b8be0 : { *(.text.d20f_list_element_802b8be0) }
  .rodata 0x803d80e0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
