/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25g_hands_transform_800697ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4Vec3 = 0x80343740;
inverse_801f6c2c = 0x801f6c2c;
multiply_801f68c8 = 0x801f68c8;
rotation_801f757c = 0x801f757c;
scale_801f7794 = 0x801f7794;
to_matrix_801f74d0 = 0x801f74d0;
translate_801f77f4 = 0x801f77f4;
update_800694f4 = 0x800694f4;
view_8015aa04 = 0x8015aa04;
SECTIONS {
  .text.w3d_d25g_hands_transform_800697ac 0x800697ac : { *(.text.w3d_d25g_hands_transform_800697ac) }
  .rodata 0x8037a984 : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; camera_804aa8c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
