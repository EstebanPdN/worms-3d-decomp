/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27a_fade_out_update_80043f00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_a_80427468 = 0x80427468;
g_b_8042745c = 0x8042745c;
w3d_cx9c_sinf_802e88ac = 0x802e88ac;
w3d_hud_properties_8011adf8 = 0x8011adf8;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
SECTIONS {
  .text.w3d_d27a_fade_out_update_80043f00 0x80043f00 : { *(.text.w3d_d27a_fade_out_update_80043f00) }
  .rodata 0x80374e30 : { *(.rodata) }
  .sdata 0x804aa97c (NOLOAD) : {
    . = 0x0; g_duration_804aa97c = .;
    . = 0x4a38; g_name_804af3b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
