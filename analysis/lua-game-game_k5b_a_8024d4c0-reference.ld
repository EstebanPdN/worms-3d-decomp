/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k5b_buffer_pair_construct_8024d4c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8024bc08 = 0x8024bc08;
lbl_8041b848 = 0x8041b848;
w3d_array_write_802514f8 = 0x802514f8;
w3d_array_write_802515b4 = 0x802515b4;
SECTIONS {
  .text.w3d_k5b_buffer_pair_construct_8024d4c0 0x8024d4c0 : { *(.text.w3d_k5b_buffer_pair_construct_8024d4c0) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
