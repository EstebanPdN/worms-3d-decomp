/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f1a_eye_vector_8001a770)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8036af50 = 0x8036af50;
lbl_8041e838 = 0x8041e838;
lbl_8041e844 = 0x8041e844;
w3d_auto_800fc270 = 0x800fc270;
SECTIONS {
  .text.w3d_f1a_eye_vector_8001a770 0x8001a770 : { *(.text.w3d_f1a_eye_vector_8001a770) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
