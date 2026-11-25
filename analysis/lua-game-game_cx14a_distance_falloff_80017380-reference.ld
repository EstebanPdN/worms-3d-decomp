/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx14a_distance_falloff_80017380)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_80016bec = 0x80016bec;
factor_800155d0 = 0x800155d0;
sqrt_802e82c0 = 0x802e82c0;
target_8041d3a0 = 0x8041d3a0;
SECTIONS {
  .text.w3d_cx14a_distance_falloff_80017380 0x80017380 : { *(.text.w3d_cx14a_distance_falloff_80017380) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; parameters_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
