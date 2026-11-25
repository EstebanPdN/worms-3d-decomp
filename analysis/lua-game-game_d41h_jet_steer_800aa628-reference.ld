/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d41h_jet_steer_800aa628)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
A__C5Mat33i = 0x80343bb4;
acos_802e79e0 = 0x802e79e0;
axis_angle_801f6480 = 0x801f6480;
blend_800abc18 = 0x800abc18;
get_float_80178df0 = 0x80178df0;
normalize_801f6c2c = 0x801f6c2c;
sqrt_802e82c0 = 0x802e82c0;
view_matrix_8015aa04 = 0x8015aa04;
SECTIONS {
  .text.d41h_jet_steer_800aa628 0x800aa628 : { *(.text.d41h_jet_steer_800aa628) }
  .rodata 0x80381a24 : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; lbl_804aa8c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
