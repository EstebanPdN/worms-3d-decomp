/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_refresh_service_8021ad34)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020b680__FPv = 0x8020b680;
lbl_8041ca50 = 0x8041ca50;
SECTIONS {
  .text.w3d_s21_refresh_service_8021ad34 0x8021ad34 : { *(.text.w3d_s21_refresh_service_8021ad34) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
