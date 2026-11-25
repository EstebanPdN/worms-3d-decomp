/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_hud_reset_80047e94)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_default_offset_80427468 = 0x80427468;
w3d_f32_803763bc = 0x803763bc;
w3d_hud_properties_8011adf8 = 0x8011adf8;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
w3d_str_80374dd8 = 0x80374dd8;
SECTIONS {
  .text.w3d_k10a_hud_reset_80047e94 0x80047e94 : { *(.text.w3d_k10a_hud_reset_80047e94) }
  .sdata 0x804aa980 (NOLOAD) : {
    . = 0x0; w3d_f32_804aa980 = .;
    . = 0x4a34; w3d_text_804af3b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
