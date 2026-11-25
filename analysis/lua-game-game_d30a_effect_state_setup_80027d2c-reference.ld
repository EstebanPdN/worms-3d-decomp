/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30a_effect_state_setup_80027d2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_a_80415c00 = 0x80415c00;
g_b_80415cb0 = 0x80415cb0;
g_c_80415c10 = 0x80415c10;
g_d_80416560 = 0x80416560;
g_e_8040e078 = 0x8040e078;
w3d_s10_service_forward_8020b680 = 0x8020b680;
SECTIONS {
  .text.w3d_d30a_effect_state_setup_80027d2c 0x80027d2c : { *(.text.w3d_d30a_effect_state_setup_80027d2c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
