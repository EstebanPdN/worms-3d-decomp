/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25a_drift_step_8000e9bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_continue_8000affc = 0x8000affc;
w3d_float_80369fcc = 0x80369fcc;
w3d_float_80369fd0 = 0x80369fd0;
w3d_random_vector_80015910 = 0x80015910;
w3d_vector_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d25a_drift_step_8000e9bc 0x8000e9bc : { *(.text.w3d_d25a_drift_step_8000e9bc) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; w3d_clock_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
