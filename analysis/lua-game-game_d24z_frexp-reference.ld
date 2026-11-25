/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24z_frexp_802e773c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_d24z_frexp_802e773c 0x802e773c : { *(.text.w3d_d24z_frexp_802e773c) }
  .sdata 0x804ac110 (NOLOAD) : {
    . = 0x0; d24z_two54_804ac110 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
