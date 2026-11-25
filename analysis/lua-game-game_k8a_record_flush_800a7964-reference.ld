/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_record_flush_800a7964)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_memcpy_802eee50 = 0x802eee50;
w3d_record_report_800a76a4 = 0x800a76a4;
SECTIONS {
  .text.w3d_k8a_record_flush_800a7964 0x800a7964 : { *(.text.w3d_k8a_record_flush_800a7964) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
