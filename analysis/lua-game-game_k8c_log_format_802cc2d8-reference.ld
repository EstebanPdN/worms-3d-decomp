/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8c_log_float_802cc2d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020c510 = 0x8020c510;
fn_8020c5c4 = 0x8020c5c4;
fn_802cc0ac = 0x802cc0ac;
fn_80341588 = 0x80341588;
fn_803426b8 = 0x803426b8;
w3d_str_803d9450 = 0x803d9450;
w3d_str_803d9454 = 0x803d9454;
SECTIONS {
  .text.w3d_k8c_log_float_802cc2d8 0x802cc2d8 : { *(.text.w3d_k8c_log_float_802cc2d8) }
  .text.w3d_k8c_log_vec3_802cc354 0x802cc354 : { *(.text.w3d_k8c_log_vec3_802cc354) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
