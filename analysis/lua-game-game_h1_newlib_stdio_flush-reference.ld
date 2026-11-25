/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(fclose)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__sinit = 0x802eb1d4;
_fwalk = 0x802ebe64;
SECTIONS {
  .text.fclose 0x802eafcc : { *(.text.fclose) }
  .text.fflush 0x802eb084 : { *(.text.fflush) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; w3d_sda_impure_ptr_804ac570 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
