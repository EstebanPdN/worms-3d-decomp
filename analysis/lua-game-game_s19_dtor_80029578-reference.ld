/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_service_destroy_80029578)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8040e288 = 0x8040e288;
w3d_service_destroy_801628ec = 0x801628ec;
SECTIONS {
  .text.s19_service_destroy_80029578 0x80029578 : { *(.text.s19_service_destroy_80029578) }
  .sdata 0x804aa860 (NOLOAD) : {
    . = 0x0; lbl_804aa860 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
