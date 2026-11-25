/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_worm_jump_clear_8014ae84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
clock_801264fc = 0x801264fc;
collided_801418c4 = 0x801418c4;
construct_801f7538 = 0x801f7538;
finish_80126524 = 0x80126524;
level_80178df0 = 0x80178df0;
limit_8014c89c = 0x8014c89c;
lookup_8003f240 = 0x8003f240;
motion_8014b8ec = 0x8014b8ec;
normal_80141564 = 0x80141564;
point_8014155c = 0x8014155c;
speed_80178ec4 = 0x80178ec4;
sqrt_802e82c0 = 0x802e82c0;
start_80126384 = 0x80126384;
steps_80141554 = 0x80141554;
trace_801412a4 = 0x801412a4;
SECTIONS {
  .text.d27d_worm_jump_clear_8014ae84 0x8014ae84 : { *(.text.d27d_worm_jump_clear_8014ae84) }
  .rodata 0x803a1390 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; kind_804aa95e = .;
    . = 0x548a; speedE_804afde8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
