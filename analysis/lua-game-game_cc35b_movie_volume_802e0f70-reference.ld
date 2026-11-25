/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc35b_movie_volume_802e0f70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802fdb6c = 0x802fdb6c;
fn_802fdb94 = 0x802fdb94;
fn_803114f0 = 0x803114f0;
SECTIONS {
  .text.w3d_cc35b_movie_volume_802e0f70 0x802e0f70 : { *(.text.w3d_cc35b_movie_volume_802e0f70) }
  .rodata 0x803db310 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
