/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16b_mesh_storage_clear_8018c490)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8017b348 = 0x8017b348;
fn_802eee50 = 0x802eee50;
SECTIONS {
  .text.w3d_cx16b_mesh_storage_clear_8018c490 0x8018c490 : { *(.text.w3d_cx16b_mesh_storage_clear_8018c490) }
  .sdata 0x804ab6b0 (NOLOAD) : {
    . = 0x0; lbl_804ab6b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
