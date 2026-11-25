/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16c_land_seed_refresh_80269f90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx16c_land_notify_8026b3f0 = 0x8026b3f0;
cx16c_land_refresh_8026bdf0 = 0x8026bdf0;
cx16c_land_state_8026c008 = 0x8026c008;
cx16c_seed_format_8020c510 = 0x8020c510;
cx16c_seed_format_803cb8d0 = 0x803cb8d0;
cx16c_seed_get_800fc230 = 0x800fc230;
cx16c_seed_key_803cb8bc = 0x803cb8bc;
cx16c_seed_prepare_8026c54c = 0x8026c54c;
cx16c_seed_set_8026c8a8 = 0x8026c8a8;
cx16c_text_default_803426b8 = 0x803426b8;
cx16c_text_finish_8020c5c4 = 0x8020c5c4;
cx16c_text_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_cx16c_land_seed_refresh_80269f90 0x80269f90 : { *(.text.w3d_cx16c_land_seed_refresh_80269f90) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
