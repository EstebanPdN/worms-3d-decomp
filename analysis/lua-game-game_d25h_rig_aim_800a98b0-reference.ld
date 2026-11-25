/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25h_rig_aim_800a98b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800a9b60 = 0x800a9b60;
fn_800fc6dc = 0x800fc6dc;
fn_80178c48 = 0x80178c48;
fn_80178df0 = 0x80178df0;
fn_802e7c30 = 0x802e7c30;
fn_802e82c0 = 0x802e82c0;
fn_802e86d4 = 0x802e86d4;
fn_802e88ac = 0x802e88ac;
fn_802e8988 = 0x802e8988;
SECTIONS {
  .text.w3d_d25h_rig_aim_800a98b0 0x800a98b0 : { *(.text.w3d_d25h_rig_aim_800a98b0) }
  .rodata 0x80381984 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
