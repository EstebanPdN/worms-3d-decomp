/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801a19cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_auto_801a19cc 0x801a19cc : { *(.text.w3d_auto_801a19cc) }
  .text.w3d_auto_80208304 0x80208304 : { *(.text.w3d_auto_80208304) }
  .text.w3d_auto_80208384 0x80208384 : { *(.text.w3d_auto_80208384) }
  .text.w3d_auto_80208404 0x80208404 : { *(.text.w3d_auto_80208404) }
  .text.w3d_auto_80208484 0x80208484 : { *(.text.w3d_auto_80208484) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
