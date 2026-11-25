/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31e_read_object_file_80202714)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__builtin_vec_delete = 0x801fe240;
__builtin_vec_new = 0x801fe220;
cc42b_sort_dispatch_802025dc = 0x802025dc;
fn_80202c5c = 0x80202c5c;
fn_80202f34 = 0x80202f34;
s_bad = 0x803b2b24;
tsonnet_c26_read_swap_80202bb4 = 0x80202bb4;
tsonnet_c26_skip_records_80202b18 = 0x80202b18;
w3d_auto_80202f28 = 0x80202f28;
w3d_auto_8020b648 = 0x8020b648;
w3d_d26e_read_records_802029b8 = 0x802029b8;
w3d_trace_stub_80347324 = 0x80347324;
SECTIONS {
  .text.w3d_d31e_read_object_file_80202714 0x80202714 : { *(.text.w3d_d31e_read_object_file_80202714) }
  .sdata 0x804b0640 (NOLOAD) : {
    . = 0x0; g_trace = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
