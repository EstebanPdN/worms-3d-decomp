/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19f_set_panel_mode_802b68f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d19f_mode_base_802b16c4 = 0x802b16c4;
d19f_mode_build_802b8430 = 0x802b8430;
d19f_mode_list_active_802bcc40 = 0x802bcc40;
d19f_mode_list_size_802bc71c = 0x802bc71c;
d19f_mode_min_step_803d7ffc = 0x803d7ffc;
d19f_mode_property_802bfba4 = 0x802bfba4;
d19f_mode_release_8015fd1c = 0x8015fd1c;
d19f_mode_reset_802b929c = 0x802b929c;
d19f_mode_update_802b8754 = 0x802b8754;
SECTIONS {
  .text.d19f_set_panel_mode_802b68f4 0x802b68f4 : { *(.text.d19f_set_panel_mode_802b68f4) }
  .rodata 0x803d8000 : { *(.rodata) }
  .sdata 0x804abb4c (NOLOAD) : {
    . = 0x0; d19f_mode_lock_804abb4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
