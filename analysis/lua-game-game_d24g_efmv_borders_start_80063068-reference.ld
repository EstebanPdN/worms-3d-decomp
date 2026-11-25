/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_efmv_borders_start_80063068)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
arena_alloc_801613f0 = 0x801613f0;
as_80342a74 = 0x80342a74;
as_80342a78 = 0x80342a78;
as_mesh_8034380c = 0x8034380c;
context_80165254 = 0x80165254;
count_80178d1c = 0x80178d1c;
load_8015adf4 = 0x8015adf4;
mesh_a_8018963c = 0x8018963c;
mesh_alloc_8018920c = 0x8018920c;
mesh_b_80189518 = 0x80189518;
mesh_c_80189760 = 0x80189760;
mesh_flags_80189704 = 0x80189704;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
read_800fc1b0 = 0x800fc1b0;
s_80379b2c = 0x80379b2c;
s_80379b3c = 0x80379b3c;
s_80379b50 = 0x80379b50;
s_80379b64 = 0x80379b64;
s_80379b78 = 0x80379b78;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
subscribe_80162024 = 0x80162024;
vt_8040db38 = 0x8040db38;
write_bool_800fc43c = 0x800fc43c;
SECTIONS {
  .text.w3d_d24g_efmv_borders_start_80063068 0x80063068 : { *(.text.w3d_d24g_efmv_borders_start_80063068) }
  .rodata 0x80379b84 : { *(.rodata) }
  .sdata 0x804ad528 (NOLOAD) : {
    . = 0x0; msg_804ad528 = .;
    . = 0x10; msg_804ad538 = .;
    . = 0x20; msg_804ad548 = .;
    . = 0x422c; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
