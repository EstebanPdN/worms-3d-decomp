/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24h_water_light_800c41b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_802e86d4 = 0x802e86d4;
fn_802e88ac = 0x802e88ac;
lbl_80383470 = 0x80383470;
lbl_8040db38 = 0x8040db38;
w3d_float_write_800fc4c8 = 0x800fc4c8;
SECTIONS {
  .text.w3d_d24h_water_light_800c41b0 0x800c41b0 : { *(.text.w3d_d24h_water_light_800c41b0) }
  .rodata 0x80383480 : { *(.rodata) }
  .sdata 0x804aade8 (NOLOAD) : {
    . = 0x0; lbl_804aade8 = .;
    . = 0x4; lbl_804aadec = .;
    . = 0x39a4; lbl_804ae78c = .;
    . = 0x696c; lbl_804b1754 = .;
    . = 0x69a0; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
