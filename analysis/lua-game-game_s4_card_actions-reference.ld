/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_card_reset)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_802aba18 = 0x802aba18;
w3d_card_clear_resources_8028aab0 = 0x8028aab0;
w3d_card_prepare_8028a4a8 = 0x8028a4a8;
w3d_f32_803cfa44 = 0x803cfa44;
w3d_handles_set_enabled_8006ee88 = 0x8006ee88;
w3d_report_802fb7ac = 0x802fb7ac;
w3d_set_name_800fc110 = 0x800fc110;
w3d_str_803cfa6c = 0x803cfa6c;
SECTIONS {
  .text.w3d_s4_card_reset 0x80289914 : { *(.text.w3d_s4_card_reset) }
  .text.w3d_s4_card_add_record 0x80289d2c : { *(.text.w3d_s4_card_add_record) }
  .text.w3d_s4_card_set_name 0x80289d70 : { *(.text.w3d_s4_card_set_name) }
  .text.w3d_s4_card_check_boot 0x80289da4 : { *(.text.w3d_s4_card_check_boot) }
  .text.w3d_s4_card_begin_load 0x80289e80 : { *(.text.w3d_s4_card_begin_load) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; w3d_ui_handles_804aaabc = .;
    . = 0x10a0; w3d_card_generation_804abb5c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
