/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d43c_payload_spawn_scatter_800ebad8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
add_80164514 = 0x80164514;
asin_802e7c30 = 0x802e7c30;
assign_800eb65c = 0x800eb65c;
cast_801797b4 = 0x801797b4;
create_8020b680 = 0x8020b680;
ctor_801f6034 = 0x801f6034;
empty_80341584 = 0x80341584;
euler_801a3eb0 = 0x801a3eb0;
i_8040fd78 = 0x8040fd78;
lookup_800fc1b0 = 0x800fc1b0;
position_800eb8d0 = 0x800eb8d0;
random_801610a0 = 0x801610a0;
set_axis_angle_801f656c = 0x801f656c;
sqrt_802e82c0 = 0x802e82c0;
velocity_800eb8f0 = 0x800eb8f0;
SECTIONS {
  .text.d43c_payload_spawn_scatter_800ebad8 0x800ebad8 : { *(.text.d43c_payload_spawn_scatter_800ebad8) }
  .rodata 0x8038b4f4 : { *(.rodata) }
  .sdata 0x804aab4c (NOLOAD) : {
    . = 0x0; clock_804aab4c = .;
    . = 0x6c40; world_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
