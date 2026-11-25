/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b11_jetpack_update_800adcb4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b11_jetpack_control_800ae9bc = 0x800ae9bc;
sol35b11_jetpack_direction_800aec68 = 0x800aec68;
sol35b11_jetpack_effects_800ae9d0 = 0x800ae9d0;
sol35b11_jetpack_intensity_800aee34 = 0x800aee34;
sol35b11_jetpack_lookup_80164fc8 = 0x80164fc8;
sol35b11_jetpack_modes_800ae29c = 0x800ae29c;
sol35b11_jetpack_one_803820fc = 0x803820fc;
sol35b11_jetpack_reset_800ae220 = 0x800ae220;
sol35b11_jetpack_scale_800ae6d8 = 0x800ae6d8;
sol35b11_jetpack_vectors_800ae338 = 0x800ae338;
sol35b11_jetpack_zero_803820f8 = 0x803820f8;
SECTIONS {
  .text.sol35b11_jetpack_update_800adcb4 0x800adcb4 : { *(.text.sol35b11_jetpack_update_800adcb4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
