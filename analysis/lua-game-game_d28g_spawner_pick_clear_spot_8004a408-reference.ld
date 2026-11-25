/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28g_spawner_pick_clear_spot_8004a408)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._5Probe = 0x80126230;
__5Probe = 0x80126184;
finish_80126524__5Probe = 0x80126524;
next_801264fc__5Probe = 0x801264fc;
rest_pos_8043ae20 = 0x8043ae20;
set_direction_80126384__5ProbeP3Veci = 0x80126384;
set_mask_8012632c__5Probei = 0x8012632c;
set_position_801262c0__5ProbeP3Vec = 0x801262c0;
set_radius_8012629c__5Probef = 0x8012629c;
sweep_800b0824 = 0x800b0824;
w3d_auto_8003f240 = 0x8003f240;
w3d_auto_801610a0 = 0x801610a0;
w3d_auto_80178df0 = 0x80178df0;
w3d_fn_8004b3f0 = 0x8004b3f0;
SECTIONS {
  .text.w3d_d28g_spawner_pick_clear_spot_8004a408 0x8004a408 : { *(.text.w3d_d28g_spawner_pick_clear_spot_8004a408) }
  .rodata 0x80376f24 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; id_804aa95e = .;
    . = 0x6e06; hits_804b1764 = .;
    . = 0x6e82; ground_804b17e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
