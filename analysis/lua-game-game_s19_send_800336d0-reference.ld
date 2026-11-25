/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_send_range_800336d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_804140d0 = 0x804140d0;
w3d_s10_service_forward_8020b680 = 0x8020b680;
SECTIONS {
  .text.s19_send_range_800336d0 0x800336d0 : { *(.text.s19_send_range_800336d0) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
