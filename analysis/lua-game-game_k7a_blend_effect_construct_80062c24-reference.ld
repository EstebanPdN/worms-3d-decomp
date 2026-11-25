/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k7a_blend_effect_construct_80062c24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ctor_8015fef0 = 0x8015fef0;
w3d_f32_80379b00 = 0x80379b00;
w3d_f32_80379b04 = 0x80379b04;
w3d_f32_80379b08 = 0x80379b08;
w3d_f32_80379b0c = 0x80379b0c;
w3d_f32_80379b10 = 0x80379b10;
w3d_vtable_8040ed80 = 0x8040ed80;
SECTIONS {
  .text.w3d_k7a_blend_effect_construct_80062c24 0x80062c24 : { *(.text.w3d_k7a_blend_effect_construct_80062c24) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_engine_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
