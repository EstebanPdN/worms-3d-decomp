/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30s_finish_type_801e8d9c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__vt_11D30sUnknown = 0x80413a38;
__vt_14D30sFinishRecv = 0x80417150;
__vt_14D30sFinishSlot = 0x80417130;
atexit = 0x802ed7e0;
d30s_receiver_8045e06c = 0x8045e06c;
malloc = 0x80212fd4;
on_event__14D30sFinishRecvPv = 0x80356c10;
w3d_cc17c_collect_members_801e9c2c = 0x801e9c2c;
w3d_d28e_register_type_801e90fc = 0x801e90fc;
w3d_d30s_receiver_dtor_801e8d70 = 0x801e8d70;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_local_static_80210610 = 0x80210610;
SECTIONS {
  .text.d30s_finish_type_801e8d9c 0x801e8d9c : { *(.text.d30s_finish_type_801e8d9c) }
  .rodata 0x803b09d4 : { *(.rodata) }
  .sdata 0x804b057c (NOLOAD) : {
    . = 0x0; d30s_receiver_guard_804b057c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
