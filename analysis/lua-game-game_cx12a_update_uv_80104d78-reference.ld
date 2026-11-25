/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12a_update_uv_80104d78)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
initial_80399828 = 0x80399828;
list_8044b694 = 0x8044b694;
one_80399840 = 0x80399840;
params_803fce44 = 0x803fce44;
query_800fc270 = 0x800fc270;
rate_8039982c = 0x8039982c;
scale_80399838 = 0x80399838;
zero_8039983c = 0x8039983c;
SECTIONS {
  .text.w3d_cx12a_update_uv_80104d78 0x80104d78 : { *(.text.w3d_cx12a_update_uv_80104d78) }
  .rodata 0x80399830 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
