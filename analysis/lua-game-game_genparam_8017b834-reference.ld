/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_singleton_create_8017b834)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__18w3d_class_8017b9c8 = 0x8017b9c8;
__nw__18w3d_class_8017b9c8Ui = 0x801fe1d8;
fn_8017b8c4 = 0x8017b8c4;
fn_8017b8ec = 0x8017b8ec;
fn_8020b648 = 0x8020b648;
fn_8020fd04 = 0x8020fd04;
lbl_80412790 = 0x80412790;
w3d_registry_80457014 = 0x80457014;
SECTIONS {
  .text.w3d_singleton_create_8017b834 0x8017b834 : { *(.text.w3d_singleton_create_8017b834) }
  .sdata 0x804ab600 (NOLOAD) : {
    . = 0x0; w3d_singleton_804ab600 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
