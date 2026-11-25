/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30a_shot_sphere_collide_8003e3a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cxa_normalized_impulse_8003eb1c = 0x8003eb1c;
d19c_nearest_sphere_801263fc = 0x801263fc;
sqrt_802e82c0 = 0x802e82c0;
w3d_actor_handle_member_set_bounds = 0x80126278;
w3d_auto_8003f240 = 0x8003f240;
w3d_cx11a_query_hit_delta_800418ac = 0x800418ac;
SECTIONS {
  .text.w3d_d30a_shot_sphere_collide_8003e3a4 0x8003e3a4 : { *(.text.w3d_d30a_shot_sphere_collide_8003e3a4) }
  .rodata 0x80374654 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; w3d_map_804aa95e = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
