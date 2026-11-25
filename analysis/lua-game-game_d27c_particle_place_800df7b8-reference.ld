/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_particle_place_800df7b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cos_802e86d4 = 0x802e86d4;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
empty_80342a74 = 0x80342a74;
lift_80389cbc = 0x80389cbc;
owner_800dfdf4 = 0x800dfdf4;
request_8015cd04 = 0x8015cd04;
sin_802e88ac = 0x802e88ac;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.d27c_particle_place_800df7b8 0x800df7b8 : { *(.text.d27c_particle_place_800df7b8) }
  .rodata 0x80389cc0 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; svc_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
