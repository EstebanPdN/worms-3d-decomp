/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_hit_radius_8028b818)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
factor_803cfcbc = 0x803cfcbc;
fn_802b22e4 = 0x802b22e4;
fn_802e82c0 = 0x802e82c0;
zero_803cfcc0 = 0x803cfcc0;
SECTIONS {
  .text.w3d_hit_radius_8028b818 0x8028b818 : { *(.text.w3d_hit_radius_8028b818) }
  .sdata 0x804abb4c (NOLOAD) : {
    . = 0x0; mode_804abb4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
