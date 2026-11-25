/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29e_print_fields_80200494)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
lbl_803b2a68 = 0x803b2a68;
lbl_803b2a6c = 0x803b2a6c;
lbl_803b2a70 = 0x803b2a70;
lbl_803b2a74 = 0x803b2a74;
lbl_8045ed94 = 0x8045ed94;
w3d_forward_virtual_80200460 = 0x80200460;
w3d_string_append = 0x8020bf2c;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_format = 0x8020c510;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d29e_print_fields_80200494 0x80200494 : { *(.text.w3d_d29e_print_fields_80200494) }
  .sdata 0x804b063c (NOLOAD) : {
    . = 0x0; lbl_804b063c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
