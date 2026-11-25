/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_update_render_clock_8015caec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80165254 = 0x80165254;
fn_8017892c = 0x8017892c;
fn_801857f4 = 0x801857f4;
fn_801f2678 = 0x801f2678;
fn_801fc790 = 0x801fc790;
fn_8020b680 = 0x8020b680;
fn_802109dc = 0x802109dc;
lbl_803a43d4 = 0x803a43d4;
lbl_803a43e4 = 0x803a43e4;
lbl_803a43f0 = 0x803a43f0;
lbl_80412450 = 0x80412450;
lbl_804126d0 = 0x804126d0;
lbl_80413be8 = 0x80413be8;
lbl_804140d0 = 0x804140d0;
lbl_804149f0 = 0x804149f0;
SECTIONS {
  .text.s9_update_render_clock_8015caec 0x8015caec : { *(.text.s9_update_render_clock_8015caec) }
  .text.s9_construct_resource_owner_8017917c 0x8017917c : { *(.text.s9_construct_resource_owner_8017917c) }
  .text.s9_construct_shared_node_8017990c 0x8017990c : { *(.text.s9_construct_shared_node_8017990c) }
  .text.s9_ensure_resource_8017b6dc 0x8017b6dc : { *(.text.s9_ensure_resource_8017b6dc) }
  .sdata 0x804ab5d0 (NOLOAD) : {
    . = 0x0; lbl_804ab5d0 = .;
    . = 0x8; lbl_804ab5d8 = .;
    . = 0x2c; lbl_804ab5fc = .;
    . = 0x4a90; lbl_804b0060 = .;
    . = 0x4a98; lbl_804b0068 = .;
    . = 0x4a9c; lbl_804b006c = .;
    . = 0x4aa4; lbl_804b0074 = .;
    . = 0x4aa8; lbl_804b0078 = .;
    . = 0x4ab0; lbl_804b0080 = .;
    . = 0x4b8c; lbl_804b015c = .;
    . = 0x4b90; lbl_804b0160 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
