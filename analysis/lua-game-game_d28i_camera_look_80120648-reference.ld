/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28i_camera_look_80120648)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
actor_80150b38 = 0x80150b38;
cosf_802e86d4 = 0x802e86d4;
engine_80165254 = 0x80165254;
height_80178df0 = 0x80178df0;
index_800fc6dc = 0x800fc6dc;
lookup_80164fc8 = 0x80164fc8;
planar_80120bec = 0x80120bec;
sinf_802e88ac = 0x802e88ac;
type_803600c0 = 0x803600c0;
type_80360e10 = 0x80360e10;
type_803615f0 = 0x803615f0;
SECTIONS {
  .text.d28i_camera_look_80120648 0x80120648 : { *(.text.d28i_camera_look_80120648) }
  .rodata 0x8039b6d4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
