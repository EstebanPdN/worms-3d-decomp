/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_call_twice_80159fec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_call_80033208 = 0x80033208;
SECTIONS {
  .text.w3d_k2b_call_twice_80159fec 0x80159fec : { *(.text.w3d_k2b_call_twice_80159fec) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; w3d_global_804aa8c8 = .;
    . = 0x705c; w3d_global_804b1924 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
