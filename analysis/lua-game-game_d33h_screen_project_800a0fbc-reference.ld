/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d33h_screen_project_800a0fbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
atan2_802e7e5c = 0x802e7e5c;
s19_handle_is_one_800a14f4 = 0x800a14f4;
terra_only_a6_distance_800a1534 = 0x800a1534;
w3d_auto_800a13ec = 0x800a13ec;
w3d_auto_800a1458 = 0x800a1458;
w3d_auto_800a1524 = 0x800a1524;
SECTIONS {
  .text.d33h_screen_project_800a0fbc 0x800a0fbc : { *(.text.d33h_screen_project_800a0fbc) }
  .rodata 0x803808e4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
