/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_aram_base)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_aram_base 0x80311d08 : { *(.text.w3d_aram_base) }
  .text.w3d_aram_size 0x80311d10 : { *(.text.w3d_aram_size) }
  .sdata 0x804b13fc (NOLOAD) : {
    . = 0x0; w3d_ref_aram_size = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
