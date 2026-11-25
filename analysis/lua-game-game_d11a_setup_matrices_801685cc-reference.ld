/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d11a_setup_matrices_801685cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d11a_concat_80302b8c = 0x80302b8c;
d11a_identity_80302b60 = 0x80302b60;
d11a_scale_80302e9c = 0x80302e9c;
d11a_translate_80302e68 = 0x80302e68;
SECTIONS {
  .text.d11a_setup_matrices_801685cc 0x801685cc : { *(.text.d11a_setup_matrices_801685cc) }
  .rodata 0x803a4f84 : { *(.rodata) }
  .sdata 0x804b1888 (NOLOAD) : {
    . = 0x0; d11a_screen_804b1888 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
