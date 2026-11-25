/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28d_worm_air_move_80146190)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
air_80146aa4 = 0x80146aa4;
apply_80153f80 = 0x80153f80;
blocked_80146b84 = 0x80146b84;
clock_801264fc = 0x801264fc;
fieldA_8014156c = 0x8014156c;
fieldB_80141574 = 0x80141574;
finish_80126524 = 0x80126524;
landA_8014dc60 = 0x8014dc60;
landB_8014dc04 = 0x8014dc04;
lookup_8003f240 = 0x8003f240;
normal_80141564 = 0x80141564;
point_8014155c = 0x8014155c;
slope_80149348 = 0x80149348;
sqrt_802e82c0 = 0x802e82c0;
steps_80141554 = 0x80141554;
sweep_801263bc = 0x801263bc;
trace_801412a4 = 0x801412a4;
SECTIONS {
  .text.d28d_worm_air_move_80146190 0x80146190 : { *(.text.d28d_worm_air_move_80146190) }
  .rodata 0x803a0f90 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; kind_804aa95e = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
