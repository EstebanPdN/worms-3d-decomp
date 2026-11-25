/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_singleton_create_80206d54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__18w3d_class_80206ee8 = 0x80206ee8;
__nw__18w3d_class_80206ee8Ui = 0x801fe1d8;
fn_80206de4 = 0x80206de4;
fn_80206e0c = 0x80206e0c;
fn_8020b648 = 0x8020b648;
fn_8020fd04 = 0x8020fd04;
lbl_804191b0 = 0x804191b0;
w3d_registry_8045ee24 = 0x8045ee24;
SECTIONS {
  .text.w3d_singleton_create_80206d54 0x80206d54 : { *(.text.w3d_singleton_create_80206d54) }
  .sdata 0x804ab9ac (NOLOAD) : {
    . = 0x0; w3d_singleton_804ab9ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
