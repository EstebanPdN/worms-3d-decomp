/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_efmv_borders_update_80062ea0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
end_8015fd1c = 0x8015fd1c;
mesh_a_8018963c = 0x8018963c;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
value_80178df0 = 0x80178df0;
vt_8040db38 = 0x8040db38;
zero_80379b14 = 0x80379b14;
SECTIONS {
  .text.w3d_d24g_efmv_borders_update_80062ea0 0x80062ea0 : { *(.text.w3d_d24g_efmv_borders_update_80062ea0) }
  .rodata 0x80379b18 : { *(.rodata) }
  .sdata 0x804ad530 (NOLOAD) : {
    . = 0x0; c_804ad530 = .;
    . = 0x4224; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
