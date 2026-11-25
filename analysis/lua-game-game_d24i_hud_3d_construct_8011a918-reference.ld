/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_hud_3d_construct_8011a918)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24i_as_object_80342a74 = 0x80342a74;
d24i_base_construct_8015fef0 = 0x8015fef0;
d24i_name_8039ae48 = 0x8039ae48;
d24i_name_8039ae64 = 0x8039ae64;
d24i_setting_lookup_800fc1b0 = 0x800fc1b0;
d24i_vtable_80410a20 = 0x80410a20;
d24i_zero_8039ae80 = 0x8039ae80;
SECTIONS {
  .text.d24i_hud_3d_construct_8011a918 0x8011a918 : { *(.text.d24i_hud_3d_construct_8011a918) }
  .sdata 0x804af3b0 (NOLOAD) : {
    . = 0x0; d24i_default_804af3b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
