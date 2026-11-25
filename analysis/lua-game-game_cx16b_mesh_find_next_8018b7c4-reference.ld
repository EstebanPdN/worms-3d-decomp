/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16b_mesh_find_next_8018b7c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_cx16b_mesh_find_next_8018b7c4 0x8018b7c4 : { *(.text.w3d_cx16b_mesh_find_next_8018b7c4) }
  .sdata 0x804b18ac (NOLOAD) : {
    . = 0x0; lbl_804b18ac = .;
    . = 0x4; lbl_804b18b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
