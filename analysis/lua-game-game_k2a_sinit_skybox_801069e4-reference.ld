/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k2a_sinit_skybox_801069e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80104694 = 0x80104694;
__16W3dType_80160038PvN21ii = 0x80160038;
w3d_f32_803999a4 = 0x803999a4;
w3d_sky_8044b67c = 0x8044b67c;
w3d_sky_8044b694 = 0x8044b694;
w3d_str_803617d0 = 0x803617d0;
w3d_str_803e83e0 = 0x803e83e0;
w3d_type_803610e0 = 0x803610e0;
SECTIONS {
  .text.k2a_sinit_skybox_801069e4 0x801069e4 : { *(.text.k2a_sinit_skybox_801069e4) }
  .sdata 0x804af1e8 (NOLOAD) : {
    . = 0x0; w3d_sky_804af1e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
