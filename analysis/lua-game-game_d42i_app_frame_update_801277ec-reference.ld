/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d42i_app_frame_update_801277ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
app_enter_80129878 = 0x80129878;
app_invert_801f69ec = 0x801f69ec;
app_leave_801298cc = 0x801298cc;
app_log_80207ca4 = 0x80207ca4;
app_mode_start_8006af38 = 0x8006af38;
app_paused_8006ee18 = 0x8006ee18;
app_paused_name_8039bd04 = 0x8039bd04;
app_reset_8015cbe0 = 0x8015cbe0;
app_send_range_800336d0 = 0x800336d0;
app_setting_read_800fc1f0 = 0x800fc1f0;
app_setting_write_800fc110 = 0x800fc110;
app_text_format_803434d4 = 0x803434d4;
app_update_8015caec = 0x8015caec;
app_update_8039bcf8 = 0x8039bcf8;
app_version_format_8039bcdc = 0x8039bcdc;
app_version_name_8039bce4 = 0x8039bce4;
app_zero_8039bd58 = 0x8039bd58;
SECTIONS {
  .text.d42i_app_frame_update_801277ec 0x801277ec : { *(.text.d42i_app_frame_update_801277ec) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; app_pending_804aa8c8 = .;
    . = 0x1f4; app_mode_804aaabc = .;
    . = 0x7d4; app_published_804ab09c = .;
    . = 0xb20; app_dirty_804ab3e8 = .;
    . = 0x4ccc; app_version_804af594 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
