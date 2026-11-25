/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_singleton_create_801b2ab8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__18w3d_class_801b2c4c = 0x801b2c4c;
__nw__18w3d_class_801b2c4cUi = 0x801fe1d8;
fn_801b2b48 = 0x801b2b48;
fn_801b2b70 = 0x801b2b70;
fn_8020b648 = 0x8020b648;
fn_8020fd04 = 0x8020fd04;
lbl_804143e0 = 0x804143e0;
w3d_registry_8045ce60 = 0x8045ce60;
SECTIONS {
  .text.w3d_singleton_create_801b2ab8 0x801b2ab8 : { *(.text.w3d_singleton_create_801b2ab8) }
  .sdata 0x804ab7a4 (NOLOAD) : {
    . = 0x0; w3d_singleton_804ab7a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
