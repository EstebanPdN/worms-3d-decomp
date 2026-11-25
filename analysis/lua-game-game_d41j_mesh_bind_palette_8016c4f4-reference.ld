/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41j_mesh_bind_palette_8016c4f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80166fd0 = 0x80166fd0;
fn_802fa988 = 0x802fa988;
fn_8030a270 = 0x8030a270;
fn_8030a2a8 = 0x8030a2a8;
SECTIONS {
  .text.w3d_d41j_mesh_bind_palette_8016c4f4 0x8016c4f4 : { *(.text.w3d_d41j_mesh_bind_palette_8016c4f4) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; heap_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
