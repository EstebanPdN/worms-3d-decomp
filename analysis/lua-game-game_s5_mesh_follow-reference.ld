/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_mesh_follow_owner_800d56bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_handle_member_query_801265ec = 0x801265ec;
w3d_owner_resolve_80164fc8 = 0x80164fc8;
SECTIONS {
  .text.w3d_mesh_follow_owner_800d56bc 0x800d56bc : { *(.text.w3d_mesh_follow_owner_800d56bc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
