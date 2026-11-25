/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28d_worm_ground_probe_8014f18c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._5Probe = 0x80126230;
__5Probe = 0x80126184;
acos_802e79e0 = 0x802e79e0;
lookup_8003f240 = 0x8003f240;
probe_group_8012632c = 0x8012632c;
probe_mask_801262e4 = 0x801262e4;
probe_nearest_801263fc = 0x801263fc;
probe_owner_80126308 = 0x80126308;
probe_position_801262c0 = 0x801262c0;
probe_radius_8012629c = 0x8012629c;
slope_80149348 = 0x80149348;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d28d_worm_ground_probe_8014f18c 0x8014f18c : { *(.text.d28d_worm_ground_probe_8014f18c) }
  .rodata 0x803a1784 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; kind_804aa95e = .;
    . = 0x6e32; hits_804b1790 = .;
    . = 0x6e46; hitT_804b17a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
