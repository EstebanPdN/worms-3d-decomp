/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(fopen)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fopen_r_802eb3c8 = 0x802eb3c8;
w3d_strtod_802ee800 = 0x802ee800;
SECTIONS {
  .text.fopen 0x802eb4b4 : { *(.text.fopen) }
  .text.atof 0x802ed878 : { *(.text.atof) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; w3d_sda_impure_ptr_804ac570 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
