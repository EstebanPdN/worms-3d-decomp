/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25h_lamp_update_800c021c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800b0824 = 0x800b0824;
fn_800c06a0 = 0x800c06a0;
lbl_8043c3ac = 0x8043c3ac;
lbl_8043c3b8 = 0x8043c3b8;
lbl_8043c3c4 = 0x8043c3c4;
lbl_8043c3d0 = 0x8043c3d0;
SECTIONS {
  .text.w3d_d25h_lamp_update_800c021c 0x800c021c : { *(.text.w3d_d25h_lamp_update_800c021c) }
  .rodata 0x80382f20 : { *(.rodata) }
  .sdata 0x804aada8 (NOLOAD) : {
    . = 0x0; lbl_804aada8 = .;
    . = 0x69bc; lbl_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
