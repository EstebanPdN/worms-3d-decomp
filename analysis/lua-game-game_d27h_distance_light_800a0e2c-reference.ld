/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27h_distance_light_800a0e2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_ambient_80437d24 = 0x80437d24;
w3d_normalize_801f6c2c = 0x801f6c2c;
SECTIONS {
  .text.d27h_distance_light_800a0e2c 0x800a0e2c : { *(.text.d27h_distance_light_800a0e2c) }
  .rodata 0x803808d4 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; g_scene_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
