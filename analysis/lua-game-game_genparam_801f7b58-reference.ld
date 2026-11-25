/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_singleton_create_801f7b58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__18w3d_class_801f7cec = 0x801f7cec;
__18w3d_class_8020dfdc = 0x8020dfdc;
__nw__18w3d_class_801f7cecUi = 0x801fe1d8;
__nw__18w3d_class_8020dfdcUi = 0x801fe1d8;
fn_801f7be8 = 0x801f7be8;
fn_801f7c10 = 0x801f7c10;
fn_8020b648 = 0x8020b648;
fn_8020ded8 = 0x8020ded8;
fn_8020df00 = 0x8020df00;
fn_8020fd04 = 0x8020fd04;
lbl_80418070 = 0x80418070;
lbl_80419500 = 0x80419500;
w3d_registry_8045e7b8 = 0x8045e7b8;
w3d_registry_80463360 = 0x80463360;
SECTIONS {
  .text.w3d_singleton_create_801f7b58 0x801f7b58 : { *(.text.w3d_singleton_create_801f7b58) }
  .text.w3d_singleton_create_8020de48 0x8020de48 : { *(.text.w3d_singleton_create_8020de48) }
  .sdata 0x804ab8f8 (NOLOAD) : {
    . = 0x0; w3d_singleton_804ab8f8 = .;
    . = 0x13c; w3d_singleton_804aba34 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
