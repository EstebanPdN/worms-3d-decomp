/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_light_set_colour_800c136c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ambient_8043c3d0 = 0x8043c3d0;
w3d_light_range_8043c384 = 0x8043c384;
SECTIONS {
  .text.w3d_light_set_colour_800c136c 0x800c136c : { *(.text.w3d_light_set_colour_800c136c) }
  .sdata 0x804aada8 (NOLOAD) : {
    . = 0x0; w3d_light_source_804aada8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
