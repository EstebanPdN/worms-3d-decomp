/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_land_point_search_8008dd54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._5Probe = 0x80126230;
__5Probe = 0x80126184;
w3d_float_read_800fc270 = 0x800fc270;
w3d_ground_8043ae20 = 0x8043ae20;
w3d_ground_query_800b0788 = 0x800b0788;
w3d_probe_reset_80126524 = 0x80126524;
w3d_probe_result_801264fc = 0x801264fc;
w3d_probe_run_80126334 = 0x80126334;
w3d_probe_set_group_8012632c = 0x8012632c;
w3d_probe_set_mask_801262e4 = 0x801262e4;
w3d_probe_set_position_801262c0 = 0x801262c0;
w3d_probe_set_radius_8012629c = 0x8012629c;
w3d_random_80162bc8 = 0x80162bc8;
w3d_string_8037e150 = 0x8037e150;
SECTIONS {
  .text.w3d_d24b_land_point_search_8008dd54 0x8008dd54 : { *(.text.w3d_d24b_land_point_search_8008dd54) }
  .rodata 0x8037e15c : { *(.rodata) }
  .sdata 0x804b17e0 (NOLOAD) : {
    . = 0x0; w3d_land_804b17e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
