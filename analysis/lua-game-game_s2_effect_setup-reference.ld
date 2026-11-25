/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80106118)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_80399918 = 0x80399918;
w3d_fn_80105ac8 = 0x80105ac8;
w3d_fn_801d4544 = 0x801d4544;
w3d_fn_801ef174 = 0x801ef174;
w3d_fn_8020b680 = 0x8020b680;
w3d_obj_80362844 = 0x80362844;
w3d_obj_80415c00 = 0x80415c00;
w3d_obj_80415cb0 = 0x80415cb0;
w3d_obj_80417000 = 0x80417000;
SECTIONS {
  .text.w3d_fn_80106118 0x80106118 : { *(.text.w3d_fn_80106118) }
  .text.w3d_fn_80106218 0x80106218 : { *(.text.w3d_fn_80106218) }
  .text.w3d_effect_register_80106530 0x80106530 : { *(.text.w3d_effect_register_80106530) }
  .text.w3d_effect_register_8010663c 0x8010663c : { *(.text.w3d_effect_register_8010663c) }
  .text.w3d_effect_register_80106734 0x80106734 : { *(.text.w3d_effect_register_80106734) }
  .sdata 0x804af1e8 (NOLOAD) : {
    . = 0x0; w3d_obj_804af1e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
