/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26a_distance_light_8003c938)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_ambient_804273c8 = 0x804273c8;
w3d_normalize_801f6c2c = 0x801f6c2c;
SECTIONS {
  .text.w3d_d26a_distance_light_8003c938 0x8003c938 : { *(.text.w3d_d26a_distance_light_8003c938) }
  .rodata 0x8037442c : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; g_scene_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
