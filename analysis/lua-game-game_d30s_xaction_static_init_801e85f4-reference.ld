/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30s_xaction_static_init_801e85f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__vt_11D30sUnknown = 0x80413a38;
__vt_15D30sXactionRecv = 0x804170f8;
__vt_15D30sXactionSlot = 0x804170d8;
data_8045e124 = 0x8045e124;
fn_801e74d0 = 0x801e74d0;
fn_801e8330 = 0x801e8330;
malloc = 0x80212fd4;
name_803b0998 = 0x803b0998;
on_event__15D30sXactionRecvPv = 0x8035653c;
recv_8045e010 = 0x8045e010;
tag_8036573c = 0x8036573c;
tag_803ea088 = 0x803ea088;
three_8045e024 = 0x8045e024;
type_8045e030 = 0x8045e030;
w3d_d24e_free_registry_801e8128 = 0x801e8128;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_local_static_801ea954 = 0x801ea954;
w3d_s21_construct_801e7174 = 0x801e7174;
w3d_s21_insert_sorted_80200af8 = 0x80200af8;
SECTIONS {
  .text.d30s_xaction_static_init_801e85f4 0x801e85f4 : { *(.text.d30s_xaction_static_init_801e85f4) }
  .rodata 0x803b0970 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
