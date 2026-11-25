/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_overlay_ctor_80106bd0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800e0678 = 0x800e0678;
w3d_vtable_8040ffb8 = 0x8040ffb8;
w3d_vtable_804106d0 = 0x804106d0;
SECTIONS {
  .text.w3d_k10a_overlay_ctor_80106bd0 0x80106bd0 : { *(.text.w3d_k10a_overlay_ctor_80106bd0) }
  .rodata 0x80399ac0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
