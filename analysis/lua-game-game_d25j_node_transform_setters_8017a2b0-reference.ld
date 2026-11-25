/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25j_set_translation_8017a2b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4Vec3 = 0x80343740;
float_803a706c = 0x803a706c;
float_803a7070 = 0x803a7070;
float_803a7074 = 0x803a7074;
fn_801a3eb0 = 0x801a3eb0;
fn_801f6034 = 0x801f6034;
fn_801f6448 = 0x801f6448;
fn_801f740c = 0x801f740c;
SECTIONS {
  .text.d25j_set_translation_8017a2b0 0x8017a2b0 : { *(.text.d25j_set_translation_8017a2b0) }
  .text.d25j_set_rotation_8017a670 0x8017a670 : { *(.text.d25j_set_rotation_8017a670) }
  .text.d25j_set_scale_8017aa28 0x8017aa28 : { *(.text.d25j_set_scale_8017aa28) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
