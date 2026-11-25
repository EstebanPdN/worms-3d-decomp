/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_c34_save_record_80288bc8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_build_record_802ab804 = 0x802ab804;
w3d_copy_icons_80288fe8 = 0x80288fe8;
w3d_retrieve_8028a098 = 0x8028a098;
w3d_temp_alloc_801fe0b8 = 0x801fe0b8;
w3d_temp_release_801fe160 = 0x801fe160;
SECTIONS {
  .text.tsonnet_c34_save_record_80288bc8 0x80288bc8 : { *(.text.tsonnet_c34_save_record_80288bc8) }
  .sdata 0x804abbd4 (NOLOAD) : {
    . = 0x0; w3d_ptr_804abbd4 = .;
    . = 0x4; w3d_ptr_804abbd8 = .;
    . = 0x8; w3d_ptr_804abbdc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
