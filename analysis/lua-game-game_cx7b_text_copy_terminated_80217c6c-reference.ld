/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx7b_text_copy_terminated_80217c6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memcpy = 0x802eee50;
strlen = 0x802ef9c0;
SECTIONS {
  .text.w3d_cx7b_text_copy_terminated_80217c6c 0x80217c6c : { *(.text.w3d_cx7b_text_copy_terminated_80217c6c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
