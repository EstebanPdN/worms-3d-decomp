/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_service_construct_801bb678)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80415410 = 0x80415410;
w3d_ctor_801b87c0 = 0x801b87c0;
SECTIONS {
  .text.w3d_k4b_service_construct_801bb678 0x801bb678 : { *(.text.w3d_k4b_service_construct_801bb678) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
