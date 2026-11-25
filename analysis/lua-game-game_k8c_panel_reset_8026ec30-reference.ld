/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8c_panel_reset_8026ec30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015fd1c = 0x8015fd1c;
fn_8015ff2c = 0x8015ff2c;
fn_8027035c = 0x8027035c;
fn_802afc40 = 0x802afc40;
fn_802b0fec = 0x802b0fec;
w3d_vtable_8041bdf0 = 0x8041bdf0;
w3d_vtable_8041be40 = 0x8041be40;
SECTIONS {
  .text.w3d_k8c_panel_reset_8026ec30 0x8026ec30 : { *(.text.w3d_k8c_panel_reset_8026ec30) }
  .text.w3d_k8c_panel_destroy_80270698 0x80270698 : { *(.text.w3d_k8c_panel_destroy_80270698) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
