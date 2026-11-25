/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_enable_light_slot_8016bdf8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_gx_set_attenuation_803093f4 = 0x803093f4;
w3d_gx_set_position_80309594 = 0x80309594;
w3d_light_load_8016b9ec = 0x8016b9ec;
w3d_light_reset_8016a0a4 = 0x8016a0a4;
w3d_s20_enable_slot_8016857c = 0x8016857c;
SECTIONS {
  .text.w3d_k2b_enable_light_slot_8016bdf8 0x8016bdf8 : { *(.text.w3d_k2b_enable_light_slot_8016bdf8) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; w3d_global_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
