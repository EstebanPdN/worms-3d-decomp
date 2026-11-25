/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_console_help_8004fda4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4Text = 0x803426b8;
help_lines_803f3f7c = 0x803f3f7c;
w3d_append_802cbf2c = 0x802cbf2c;
w3d_clear_802cd14c = 0x802cd14c;
w3d_flush_802cd07c = 0x802cd07c;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_write_802cbdf8 = 0x802cbdf8;
SECTIONS {
  .text.w3d_d24g_console_help_8004fda4 0x8004fda4 : { *(.text.w3d_d24g_console_help_8004fda4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
