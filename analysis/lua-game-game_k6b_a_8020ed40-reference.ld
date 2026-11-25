/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_service_copy_setting_8020ed40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80419500 = 0x80419500;
w3d_auto_8020b648 = 0x8020b648;
SECTIONS {
  .text.w3d_k6b_service_copy_setting_8020ed40 0x8020ed40 : { *(.text.w3d_k6b_service_copy_setting_8020ed40) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
