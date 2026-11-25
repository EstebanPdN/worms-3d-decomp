/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k7a_attachment_position_80135af4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80181e3c = 0x80181e3c;
w3d_empty_80343584 = 0x80343584;
w3d_empty_80343740 = 0x80343740;
w3d_mesh_instance_unbind = 0x80181e18;
SECTIONS {
  .text.w3d_k7a_attachment_position_80135af4 0x80135af4 : { *(.text.w3d_k7a_attachment_position_80135af4) }
  .sdata 0x804ab324 (NOLOAD) : {
    . = 0x0; w3d_obj_804ab324 = .;
    . = 0x4; w3d_obj_804ab328 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
