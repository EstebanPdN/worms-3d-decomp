/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17b_service_forward_800fd62c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_cc17b_service_forward_800fd62c 0x800fd62c : { *(.text.w3d_cc17b_service_forward_800fd62c) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; root_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
