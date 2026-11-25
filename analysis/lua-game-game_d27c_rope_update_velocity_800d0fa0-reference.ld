/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_rope_update_velocity_800d0fa0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
calc_800d0108 = 0x800d0108;
init_80126000 = 0x80126000;
msg_id_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.d27c_rope_update_velocity_800d0fa0 0x800d0fa0 : { *(.text.d27c_rope_update_velocity_800d0fa0) }
  .rodata 0x803881ac : { *(.rodata) }
  .sdata 0x804ae958 (NOLOAD) : {
    . = 0x0; id_804ae958 = .;
    . = 0x2dfc; heap_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
