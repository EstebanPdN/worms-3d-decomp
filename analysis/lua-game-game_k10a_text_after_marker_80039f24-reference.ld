/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_text_after_marker_80039f24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strstr = 0x802efd14;
w3d_auto_80039b6c = 0x80039b6c;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_k10a_text_after_marker_80039f24 0x80039f24 : { *(.text.w3d_k10a_text_after_marker_80039f24) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
