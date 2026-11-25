/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27a_ballistic_refine_contact_80040ff4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_accel_80427438 = 0x80427438;
g_position_80427444 = 0x80427444;
g_velocity_80427414 = 0x80427414;
SECTIONS {
  .text.w3d_d27a_ballistic_refine_contact_80040ff4 0x80040ff4 : { *(.text.w3d_d27a_ballistic_refine_contact_80040ff4) }
  .rodata 0x80374798 : { *(.rodata) }
  .sdata 0x804b17d4 (NOLOAD) : {
    . = 0x0; g_time_804b17d4 = .;
    . = 0x4; g_radius_804b17d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
