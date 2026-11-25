/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(step__4RopePC3VecP3Vec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
axis_801f7538 = 0x801f7538;
drain_800d0058 = 0x800d0058;
k_80388150 = 0x80388150;
k_80388154 = 0x80388154;
k_80388158 = 0x80388158;
limits_800d18bc = 0x800d18bc;
mul_801f740c = 0x801f740c;
probe_800d066c = 0x800d066c;
read_80178df0 = 0x80178df0;
sin_802e88ac = 0x802e88ac;
sqrt_802e82c0 = 0x802e82c0;
start_8045e788 = 0x8045e788;
vec_ctor_80343740 = 0x80343740;
zero_80388144 = 0x80388144;
SECTIONS {
  .text.step__4RopePC3VecP3Vec 0x800d0108 : { *(.text.step__4RopePC3VecP3Vec) }
  .rodata 0x80388148 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
