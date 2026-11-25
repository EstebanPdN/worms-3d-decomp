/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_tga_read_801d9f0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802ebfbc = 0x802ebfbc;
SECTIONS {
  .text.w3d_k8b_tga_read_801d9f0c 0x801d9f0c : { *(.text.w3d_k8b_tga_read_801d9f0c) }
  .rodata 0x803af8e8 : { *(.rodata) }
  .sdata 0x804ab7fc (NOLOAD) : {
    . = 0x0; lbl_804ab7fc = .;
    . = 0x4; lbl_804ab800 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
