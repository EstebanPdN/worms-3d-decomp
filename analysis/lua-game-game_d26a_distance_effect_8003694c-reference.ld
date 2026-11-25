/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26a_distance_effect_8003694c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sqrt_802e82c0 = 0x802e82c0;
w3d_fn_8003671c = 0x8003671c;
w3d_fn_80036abc = 0x80036abc;
w3d_value_80178df0 = 0x80178df0;
SECTIONS {
  .text.w3d_d26a_distance_effect_8003694c 0x8003694c : { *(.text.w3d_d26a_distance_effect_8003694c) }
  .rodata 0x80373cb0 : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; g_world_804aa8c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
