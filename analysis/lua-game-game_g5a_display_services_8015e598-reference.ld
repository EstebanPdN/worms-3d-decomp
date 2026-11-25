/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g5a_display_services_8015e598)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
display_80411e50 = 0x80411e50;
input_80411b40 = 0x80411b40;
query_8020b680 = 0x8020b680;
renderer_80411c00 = 0x80411c00;
scene_80411cf0 = 0x80411cf0;
title_803a450c = 0x803a450c;
window_80411ee8 = 0x80411ee8;
SECTIONS {
  .text.g5a_display_services_8015e598 0x8015e598 : { *(.text.g5a_display_services_8015e598) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
