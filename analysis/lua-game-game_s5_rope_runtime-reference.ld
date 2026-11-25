/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_rope_drain_handle_800d0058)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178df0 = 0x80178df0;
w3d_handle_clock_801264fc = 0x801264fc;
w3d_handle_member_call_80126334 = 0x80126334;
w3d_handle_member_query_801262c0 = 0x801262c0;
w3d_handle_member_query_80126524 = 0x80126524;
SECTIONS {
  .text.w3d_rope_drain_handle_800d0058 0x800d0058 : { *(.text.w3d_rope_drain_handle_800d0058) }
  .text.w3d_rope_rescale_800d1628 0x800d1628 : { *(.text.w3d_rope_rescale_800d1628) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
