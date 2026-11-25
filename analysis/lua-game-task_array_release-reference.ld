/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_task_array_release)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_system_heap_release = 0x802134fc;
SECTIONS {
  .text.w3d_task_array_release 0x801fe240 : { *(.text.w3d_task_array_release) }
  .text.w3d_task_array_release_backend 0x801fe288 : { *(.text.w3d_task_array_release_backend) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
