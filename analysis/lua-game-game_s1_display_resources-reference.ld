/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80041ef8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ctor_8015fef0 = 0x8015fef0;
w3d_vtable_8040e938 = 0x8040e938;
SECTIONS {
  .text.w3d_fn_80041ef8 0x80041ef8 : { *(.text.w3d_fn_80041ef8) }
  .rodata 0x80374da4 : { *(.rodata) }
  .sdata 0x804aa984 (NOLOAD) : {
    . = 0x0; w3d_active_804aa984 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
