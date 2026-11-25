/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d33g_water_shade_8007eb54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8043add8 = 0x8043add8;
lbl_8043ade4 = 0x8043ade4;
sqrt_802e82c0 = 0x802e82c0;
w3d_copy_vectors_800bd808 = 0x800bd808;
w3d_sweep_800b0824 = 0x800b0824;
SECTIONS {
  .text.w3d_d33g_water_shade_8007eb54 0x8007eb54 : { *(.text.w3d_d33g_water_shade_8007eb54) }
  .rodata 0x8037cec0 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; lbl_804b1764 = .;
    . = 0x7c; lbl_804b17e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
