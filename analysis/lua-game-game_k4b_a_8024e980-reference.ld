/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_material_slot_construct_8024e980)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8041b7a8 = 0x8041b7a8;
w3d_k4b_named_color_construct_801b4bcc = 0x801b4bcc;
SECTIONS {
  .text.w3d_k4b_material_slot_construct_8024e980 0x8024e980 : { *(.text.w3d_k4b_material_slot_construct_8024e980) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . = 0x4; lbl_804b05ac = .;
    . = 0x8; lbl_804b05b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
