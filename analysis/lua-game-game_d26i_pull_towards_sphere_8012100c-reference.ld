/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26i_pull_towards_sphere_8012100c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d19c_nearest_sphere_801263fc = 0x801263fc;
w3d_handle_member_query_801262c0 = 0x801262c0;
zero_8039b6ec = 0x8039b6ec;
SECTIONS {
  .text.d26i_pull_towards_sphere_8012100c 0x8012100c : { *(.text.d26i_pull_towards_sphere_8012100c) }
  .rodata 0x8039b6f0 : { *(.rodata) }
  .sdata 0x804b1790 (NOLOAD) : {
    . = 0x0; lbl_804b1790 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
