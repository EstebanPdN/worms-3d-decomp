/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_temporary_owner_allocate)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_temporary_allocate = 0x801fe0b8;
w3d_temporary_release = 0x801fe160;
SECTIONS {
  .text.w3d_temporary_owner_allocate 0x80198248 : { *(.text.w3d_temporary_owner_allocate) }
  .text.w3d_temporary_owner_release 0x80198280 : { *(.text.w3d_temporary_owner_release) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
