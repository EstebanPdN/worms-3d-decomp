/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17c_mesh_sinit_v2_80180340)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16W3dType_8020fbd0PvN21ii = 0x8020fbd0;
fn_8017eae4 = 0x8017eae4;
lbl_80361b98 = 0x80361b98;
lbl_80361f58 = 0x80361f58;
lbl_803e8a38 = 0x803e8a38;
SECTIONS {
  .text.w3d_cc17c_mesh_sinit_v2_80180340 0x80180340 : { *(.text.w3d_cc17c_mesh_sinit_v2_80180340) }
  .sdata 0x804b0184 (NOLOAD) : {
    . = 0x0; lbl_804b0184 = .;
    . = 0x4; lbl_804b0188 = .;
    . = 0x8; lbl_804b018c = .;
    . = 0xc; lbl_804b0190 = .;
    . = 0x10; lbl_804b0194 = .;
    . = 0x14; lbl_804b0198 = .;
    . = 0x18; lbl_804b019c = .;
    . = 0x1c; lbl_804b01a0 = .;
    . = 0x20; lbl_804b01a4 = .;
    . = 0x24; lbl_804b01a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
