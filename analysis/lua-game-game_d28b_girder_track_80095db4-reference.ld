/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28b_girder_track_80095db4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8045e788 = 0x8045e788;
sqrt_802e82c0 = 0x802e82c0;
w3d_ray_begin_801262c0 = 0x801262c0;
w3d_ray_cast_80126384 = 0x80126384;
w3d_ray_end_80126524 = 0x80126524;
w3d_ray_hit_801264fc = 0x801264fc;
w3d_sweep_800b0824 = 0x800b0824;
SECTIONS {
  .text.w3d_d28b_girder_track_80095db4 0x80095db4 : { *(.text.w3d_d28b_girder_track_80095db4) }
  .rodata 0x8037ebd0 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; lbl_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
