/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_fade_out_80126ac0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80173df0 = 0x80173df0;
w3d_empty_8034357c = 0x8034357c;
w3d_f32_8039bc6c = 0x8039bc6c;
w3d_f32_8039bc70 = 0x8039bc70;
w3d_runtime_service_set_byte_b = 0x8015af24;
SECTIONS {
  .text.w3d_k10a_fade_out_80126ac0 0x80126ac0 : { *(.text.w3d_k10a_fade_out_80126ac0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
