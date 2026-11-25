/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc39c_girder_member_8009369c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc39c_girder_8037e9dc = 0x8037e9dc;
cc39c_handle_object_80343584 = 0x80343584;
cc39c_handle_set_name_8015adf4 = 0x8015adf4;
cc39c_heap_allocate_802098d8 = 0x802098d8;
cc39c_member_attach_80126610 = 0x80126610;
cc39c_member_construct_8012656c = 0x8012656c;
cc39c_member_destroy_801265a4 = 0x801265a4;
cc39c_string_base_finish_8020c5c4 = 0x8020c5c4;
cc39c_string_from_text_8020bb54 = 0x8020bb54;
cc39c_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.cc39c_girder_member_8009369c 0x8009369c : { *(.text.cc39c_girder_member_8009369c) }
  .sdata 0x804af5bc (NOLOAD) : {
    . = 0x0; cc39c_handle_heap_804af5bc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
