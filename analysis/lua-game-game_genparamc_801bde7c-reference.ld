/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_register_block_binding_801bde7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801f0d2c = 0x801f0d2c;
fn_801f282c = 0x801f282c;
fn_80210b90 = 0x80210b90;
lbl_803abc34 = 0x803abc34;
lbl_803aecb0 = 0x803aecb0;
lbl_8045e708 = 0x8045e708;
SECTIONS {
  .text.w3d_register_block_binding_801bde7c 0x801bde7c : { *(.text.w3d_register_block_binding_801bde7c) }
  .text.w3d_register_block_binding_801ce4f0 0x801ce4f0 : { *(.text.w3d_register_block_binding_801ce4f0) }
  .text.w3d_copy_refs_801f2698 0x801f2698 : { *(.text.w3d_copy_refs_801f2698) }
  .text.w3d_copy_refs_802109fc 0x802109fc : { *(.text.w3d_copy_refs_802109fc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
