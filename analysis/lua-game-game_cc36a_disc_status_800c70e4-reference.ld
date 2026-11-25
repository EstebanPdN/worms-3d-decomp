/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc36a_disc_status_800c70e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc36a_animate_800c7ff4 = 0x800c7ff4;
cc36a_clear_800c770c = 0x800c770c;
cc36a_cover_80387984 = 0x80387984;
cc36a_display_800c71f8 = 0x800c71f8;
cc36a_error_803879a8 = 0x803879a8;
cc36a_fatal_803879bc = 0x803879bc;
cc36a_insert_80387998 = 0x80387998;
cc36a_localize_800fc2b0 = 0x800fc2b0;
SECTIONS {
  .text.cc36a_disc_status_800c70e4 0x800c70e4 : { *(.text.cc36a_disc_status_800c70e4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
