/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8c_type_shutdown_80210010)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020fe64 = 0x8020fe64;
fn_80210610 = 0x80210610;
fn_80210660 = 0x80210660;
SECTIONS {
  .text.w3d_k8c_type_shutdown_80210010 0x80210010 : { *(.text.w3d_k8c_type_shutdown_80210010) }
  .sdata 0x804aba54 (NOLOAD) : {
    . = 0x0; w3d_sdata_804aba54 = .;
    . = 0x5eb0; w3d_sdata_804b1904 = .;
    . = 0x5eb4; w3d_sdata_804b1908 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
