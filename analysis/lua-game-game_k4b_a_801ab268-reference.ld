/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_channel_set_construct_801ab268)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e81c8 = 0x801e81c8;
lbl_80413dc0 = 0x80413dc0;
lbl_80413eb8 = 0x80413eb8;
SECTIONS {
  .text.w3d_k4b_channel_set_construct_801ab268 0x801ab268 : { *(.text.w3d_k4b_channel_set_construct_801ab268) }
  .rodata 0x803aa2ac : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
