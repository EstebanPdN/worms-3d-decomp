/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_worm_lights_80139a04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__18d24d_Text_803442b4PCce = 0x803442b4;
d24d_mesh_set_resource_value_80182410 = 0x80182410;
d24d_mesh_status_80182408 = 0x80182408;
d24d_weapon_light_8039f6b0 = 0x8039f6b0;
d24d_worm_light_8039f6a0 = 0x8039f6a0;
SECTIONS {
  .text.d24d_worm_lights_80139a04 0x80139a04 : { *(.text.d24d_worm_lights_80139a04) }
  .sdata 0x804b17ec (NOLOAD) : {
    . = 0x0; d24d_resources_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
