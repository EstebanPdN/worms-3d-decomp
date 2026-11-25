/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_card_guide_show_message)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_os_panic_802fb82c = 0x802fb82c;
w3d_os_report_802fb7ac = 0x802fb7ac;
w3d_str_illegal_print_state_803d8ca4 = 0x803d8ca4;
w3d_str_memguidefig2_803d8888 = 0x803d8888;
w3d_str_mesg_corrupt_803d8b90 = 0x803d8b90;
w3d_str_mesg_damaged_803d8bb0 = 0x803d8bb0;
w3d_str_mesg_encoding_803d8c38 = 0x803d8c38;
w3d_str_mesg_format_failed_803d8c7c = 0x803d8c7c;
w3d_str_mesg_format_sure_803d8c58 = 0x803d8c58;
w3d_str_mesg_nocard_803d8c18 = 0x803d8c18;
w3d_str_mesg_nosupport_803d8bd0 = 0x803d8bd0;
w3d_str_mesg_wrongdevice_803d8bf4 = 0x803d8bf4;
w3d_str_rtrn_continue_803d8b74 = 0x803d8b74;
w3d_str_rtrn_done_803d8b5c = 0x803d8b5c;
w3d_str_stat_check_803d8adc = 0x803d8adc;
w3d_str_stat_format_803d8b1c = 0x803d8b1c;
w3d_str_stat_mount_803d8abc = 0x803d8abc;
w3d_str_stat_probe_803d8a9c = 0x803d8a9c;
w3d_str_stat_sector_803d8afc = 0x803d8afc;
w3d_str_stat_start_803d8a7c = 0x803d8a7c;
w3d_str_stat_unmount_803d8b3c = 0x803d8b3c;
SECTIONS {
  .text.w3d_card_guide_show_message 0x802c59e8 : { *(.text.w3d_card_guide_show_message) }
  .sdata 0x804abc98 (NOLOAD) : {
    . = 0x0; w3d_card_guide_last_message_804abc98 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
