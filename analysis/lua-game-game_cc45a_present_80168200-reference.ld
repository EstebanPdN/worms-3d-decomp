/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc45a_present_80168200)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc45a_abort_801683c4 = 0x801683c4;
cc45a_alpha_8030ba0c = 0x8030ba0c;
cc45a_begin_8016ee48 = 0x8016ee48;
cc45a_copy_80309254 = 0x80309254;
cc45a_draw_token_803084e0 = 0x803084e0;
cc45a_filter_80309038 = 0x80309038;
cc45a_read_token_80308594 = 0x80308594;
cc45a_report_802fb7ac = 0x802fb7ac;
cc45a_reset_8016830c = 0x8016830c;
cc45a_warning_803a4e7c = 0x803a4e7c;
SECTIONS {
  .text.cc45a_present_80168200 0x80168200 : { *(.text.cc45a_present_80168200) }
  .sdata 0x804b00e4 (NOLOAD) : {
    . = 0x0; cc45a_elapsed_804b00e4 = .;
    . = 0x4; cc45a_deadline_804b00e8 = .;
    . = 0x17a0; cc45a_graphics_804b1884 = .;
    . = 0x17a4; cc45a_display_804b1888 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
