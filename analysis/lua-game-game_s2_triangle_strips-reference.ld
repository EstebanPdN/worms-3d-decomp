/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_strip_emit_8010a918)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_strip_emit_8010a918 0x8010a918 : { *(.text.w3d_strip_emit_8010a918) }
  .text.w3d_strip_emit_8010aa60 0x8010aa60 : { *(.text.w3d_strip_emit_8010aa60) }
  .text.w3d_strip_emit_8010abc8 0x8010abc8 : { *(.text.w3d_strip_emit_8010abc8) }
  .text.w3d_strip_emit_visible_8010ad24 0x8010ad24 : { *(.text.w3d_strip_emit_visible_8010ad24) }
  .sdata 0x804af2ac (NOLOAD) : {
    . = 0x0; w3d_obj_804af2ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
