/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16b_mesh_find_next_8017f954)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80185b0c = 0x80185b0c;
SECTIONS {
  .text.w3d_cx16b_mesh_find_next_8017f954 0x8017f954 : { *(.text.w3d_cx16b_mesh_find_next_8017f954) }
  .sdata 0x804ab60c (NOLOAD) : {
    . = 0x0; lbl_804ab60c = .;
    . = 0x4; lbl_804ab610 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
