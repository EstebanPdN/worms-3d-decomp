/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31i_ambient_sky_8012b30c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
colours_80189760 = 0x80189760;
frand_8015ff7c = 0x8015ff7c;
height_80178df0 = 0x80178df0;
k15_8039d304 = 0x8039d304;
open_8018963c = 0x8018963c;
palette_80450a60 = 0x80450a60;
points_80189518 = 0x80189518;
rand_8015ff5c = 0x8015ff5c;
ref_80342a74 = 0x80342a74;
service_8015cd04 = 0x8015cd04;
sinf_802e88ac = 0x802e88ac;
sqrt_802e82c0 = 0x802e82c0;
wind_8044b688 = 0x8044b688;
SECTIONS {
  .text.d31i_ambient_sky_8012b30c 0x8012b30c : { *(.text.d31i_ambient_sky_8012b30c) }
  .rodata 0x8039d308 : { *(.rodata) }
  .sdata 0x804af610 (NOLOAD) : {
    . = 0x0; palette_ready_804af610 = .;
    . = 0x2178; runtime_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
