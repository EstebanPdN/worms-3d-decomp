/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_register_service_8008e1e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80164514 = 0x80164514;
lbl_80410358 = 0x80410358;
w3d_s10_service_forward_8020b680 = 0x8020b680;
SECTIONS {
  .text.s19_register_service_8008e1e0 0x8008e1e0 : { *(.text.s19_register_service_8008e1e0) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; lbl_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
