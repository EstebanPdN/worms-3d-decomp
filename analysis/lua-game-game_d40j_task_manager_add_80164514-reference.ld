/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40j_task_manager_add_80164514)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
engine_context_80165254 = 0x80165254;
free = 0x802134fc;
malloc = 0x80212fd4;
memmove = 0x802eeef4;
start_task_8034b418 = 0x8034b418;
type_803617d0 = 0x803617d0;
type_80361860 = 0x80361860;
type_803618f0 = 0x803618f0;
type_name_801ffea8 = 0x801ffea8;
w3d_push_heap_8034a400 = 0x8034a400;
SECTIONS {
  .text.w3d_d40j_task_manager_add_80164514 0x80164514 : { *(.text.w3d_d40j_task_manager_add_80164514) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
