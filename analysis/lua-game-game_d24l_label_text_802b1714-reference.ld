/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_label_text_802b1714)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_rename_801790bc = 0x801790bc;
strcmp = 0x802ef234;
w3d_as_80343744 = 0x80343744;
w3d_lookup_800fc1b0 = 0x800fc1b0;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_format_8020c510 = 0x8020c510;
w3d_string_header_80341884 = 0x80341884;
w3d_string_init_8020c5c0 = 0x8020c5c0;
w3d_string_release_80341588 = 0x80341588;
w3d_text_80179170 = 0x80179170;
SECTIONS {
  .text.d24l_label_text_802b1714 0x802b1714 : { *(.text.d24l_label_text_802b1714) }
  .rodata 0x803d7a20 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
