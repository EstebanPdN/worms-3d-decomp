/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_dtor_8018e510)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_8018e2e0 = 0x8018e2e0;
w3d_fn_801ea740 = 0x801ea740;
w3d_vtable_804130c0 = 0x804130c0;
w3d_vtable_804130e8 = 0x804130e8;
w3d_vtable_80413110 = 0x80413110;
w3d_vtable_80413138 = 0x80413138;
w3d_vtable_80413188 = 0x80413188;
w3d_vtable_804131b0 = 0x804131b0;
SECTIONS {
  .text.w3d_dtor_8018e510 0x8018e510 : { *(.text.w3d_dtor_8018e510) }
  .text.w3d_dtor_8018e69c 0x8018e69c : { *(.text.w3d_dtor_8018e69c) }
  .text.w3d_dtor_8018ea74 0x8018ea74 : { *(.text.w3d_dtor_8018ea74) }
  .text.w3d_dtor_8018ec10 0x8018ec10 : { *(.text.w3d_dtor_8018ec10) }
  .text.w3d_dtor_held_8018edd4 0x8018edd4 : { *(.text.w3d_dtor_held_8018edd4) }
  .text.w3d_dtor_8018ef90 0x8018ef90 : { *(.text.w3d_dtor_8018ef90) }
  .text.w3d_ifaceset_8018ff20 0x8018ff20 : { *(.text.w3d_ifaceset_8018ff20) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
