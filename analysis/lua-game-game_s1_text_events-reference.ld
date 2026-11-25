/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80044994)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_80043134 = 0x80043134;
w3d_fn_800fc2b0 = 0x800fc2b0;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_str_80374f78 = 0x80374f78;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_default = 0x803426b8;
w3d_string_format = 0x8020c510;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_fn_80044994 0x80044994 : { *(.text.w3d_fn_80044994) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
