/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_tracker_construct_801b17bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e81c8 = 0x801e81c8;
lbl_80414270 = 0x80414270;
lbl_804142c0 = 0x804142c0;
w3d_construct_801f2678 = 0x801f2678;
SECTIONS {
  .text.w3d_k4b_tracker_construct_801b17bc 0x801b17bc : { *(.text.w3d_k4b_tracker_construct_801b17bc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
