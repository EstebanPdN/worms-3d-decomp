/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ballistic_boundary_query_800d92a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_801797b4 = 0x801797b4;
w3d_cached_message_id = 0x8015f5a0;
w3d_empty_80341584 = 0x80341584;
w3d_f32_80389538 = 0x80389538;
SECTIONS {
  .text.w3d_ballistic_boundary_query_800d92a8 0x800d92a8 : { *(.text.w3d_ballistic_boundary_query_800d92a8) }
  .text.w3d_ballistic_deadline_query_800d93d0 0x800d93d0 : { *(.text.w3d_ballistic_deadline_query_800d93d0) }
  .rodata 0x80389540 : { *(.rodata) }
  .sdata 0x804aeb00 (NOLOAD) : {
    . = 0x0; w3d_ballistic_name_804aeb00 = .;
    . = 0x38; w3d_ballistic_name_804aeb38 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
