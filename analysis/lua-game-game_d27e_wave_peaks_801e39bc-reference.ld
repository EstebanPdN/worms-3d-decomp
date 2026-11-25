/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27e_wave_peaks_801e39bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memcpy = 0x802eee50;
w3d_heap_allocate_entry_b = 0x801fe220;
w3d_task_array_release = 0x801fe240;
SECTIONS {
  .text.w3d_d27e_wave_peaks_801e39bc 0x801e39bc : { *(.text.w3d_d27e_wave_peaks_801e39bc) }
  .rodata 0x803b0668 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
