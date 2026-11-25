/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f7b_orbit_vector_800e5a70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cast_80342a74 = 0x80342a74;
cast_80342a78 = 0x80342a78;
cos_802e86d4 = 0x802e86d4;
get_80178d1c = 0x80178d1c;
get_80178df0 = 0x80178df0;
sin_802e88ac = 0x802e88ac;
zero_8038a5a0 = 0x8038a5a0;
SECTIONS {
  .text.f7b_orbit_vector_800e5a70 0x800e5a70 : { *(.text.f7b_orbit_vector_800e5a70) }
  .sdata 0x804aaecc (NOLOAD) : {
    . = 0x0; config_804aaecc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
