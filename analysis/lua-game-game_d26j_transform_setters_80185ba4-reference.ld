/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26j_set_translation_80185ba4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4Vec3 = 0x80343740;
float_803a7aa4 = 0x803a7aa4;
float_803a7aa8 = 0x803a7aa8;
float_803a7aac = 0x803a7aac;
fn_801a3eb0 = 0x801a3eb0;
fn_801f6034 = 0x801f6034;
fn_801f6448 = 0x801f6448;
fn_801f740c = 0x801f740c;
SECTIONS {
  .text.d26j_set_translation_80185ba4 0x80185ba4 : { *(.text.d26j_set_translation_80185ba4) }
  .text.d26j_set_rotation_80185f10 0x80185f10 : { *(.text.d26j_set_rotation_80185f10) }
  .text.d26j_set_scale_80186254 0x80186254 : { *(.text.d26j_set_scale_80186254) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
