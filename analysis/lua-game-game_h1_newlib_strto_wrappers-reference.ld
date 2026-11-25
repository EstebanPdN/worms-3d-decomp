/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(atoi)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_strtol_r = 0x802f2fe8;
_strtoul_r = 0x802eeb30;
SECTIONS {
  .text.atoi 0x802ed89c : { *(.text.atoi) }
  .text.atol 0x802ed8c4 : { *(.text.atol) }
  .text.strtoul 0x802eecc8 : { *(.text.strtoul) }
  .text.strtol 0x802f3198 : { *(.text.strtol) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; w3d_sda_impure_ptr_804ac570 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
