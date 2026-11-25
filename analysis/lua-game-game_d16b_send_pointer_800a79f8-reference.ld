/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d16b_send_pointer_800a79f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_dispatch_800a6c80 = 0x800a6c80;
w3d_type_8040db38 = 0x8040db38;
SECTIONS {
  .text.d16b_send_pointer_800a79f8 0x800a79f8 : { *(.text.d16b_send_pointer_800a79f8) }
  .rodata 0x803814d0 : { *(.rodata) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; w3d_arena_804b1754 = .;
    . = 0x9c; w3d_cursor_804b17f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
