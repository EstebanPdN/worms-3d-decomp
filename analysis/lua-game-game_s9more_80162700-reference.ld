/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_release_reference_80162700)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178b5c = 0x80178b5c;
fn_80185b0c = 0x80185b0c;
fn_80185b24 = 0x80185b24;
fn_801ef048 = 0x801ef048;
SECTIONS {
  .text.s9_release_reference_80162700 0x80162700 : { *(.text.s9_release_reference_80162700) }
  .text.s9_count_pool_categories_80170b2c 0x80170b2c : { *(.text.s9_count_pool_categories_80170b2c) }
  .text.s9_virtual_byte_801734d0 0x801734d0 : { *(.text.s9_virtual_byte_801734d0) }
  .text.s9_count_pool_categories_8017453c 0x8017453c : { *(.text.s9_count_pool_categories_8017453c) }
  .text.s9_virtual_byte_80175044 0x80175044 : { *(.text.s9_virtual_byte_80175044) }
  .text.s9_submit_descriptors_80175f7c 0x80175f7c : { *(.text.s9_submit_descriptors_80175f7c) }
  .text.s9_submit_descriptors_80176000 0x80176000 : { *(.text.s9_submit_descriptors_80176000) }
  .text.s9_submit_descriptors_801761a4 0x801761a4 : { *(.text.s9_submit_descriptors_801761a4) }
  .text.s9_release_reference_80178884 0x80178884 : { *(.text.s9_release_reference_80178884) }
  .text.s9_update_value_80178c54 0x80178c54 : { *(.text.s9_update_value_80178c54) }
  .text.s9_update_value_80178d28 0x80178d28 : { *(.text.s9_update_value_80178d28) }
  .text.s9_update_value_80178f60 0x80178f60 : { *(.text.s9_update_value_80178f60) }
  .text.s9_release_reference_80179800 0x80179800 : { *(.text.s9_release_reference_80179800) }
  .text.s9_count_pool_categories_8017f540 0x8017f540 : { *(.text.s9_count_pool_categories_8017f540) }
  .text.s9_count_pool_categories_80187768 0x80187768 : { *(.text.s9_count_pool_categories_80187768) }
  .text.s9_virtual_byte_8018915c 0x8018915c : { *(.text.s9_virtual_byte_8018915c) }
  .text.s9_property_data_80189518 0x80189518 : { *(.text.s9_property_data_80189518) }
  .text.s9_property_data_80189704 0x80189704 : { *(.text.s9_property_data_80189704) }
  .text.s9_property_data_80189828 0x80189828 : { *(.text.s9_property_data_80189828) }
  .text.s9_property_data_80189884 0x80189884 : { *(.text.s9_property_data_80189884) }
  .sdata 0x804ab588 (NOLOAD) : {
    . = 0x0; lbl_804ab588 = .;
    . = 0x4; lbl_804ab58c = .;
    . = 0x84; lbl_804ab60c = .;
    . = 0x88; lbl_804ab610 = .;
    . = 0xf8; lbl_804ab680 = .;
    . = 0xfc; lbl_804ab684 = .;
    . = 0x6314; lbl_804b189c = .;
    . = 0x631c; lbl_804b18a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
