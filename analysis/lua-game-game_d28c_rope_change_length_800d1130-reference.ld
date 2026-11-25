/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28c_rope_change_length_800d1130)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
drain_800d0058 = 0x800d0058;
probe_800d066c = 0x800d066c;
rescale_800d1628 = 0x800d1628;
sqrt_802e82c0 = 0x802e82c0;
sum_800cfe18 = 0x800cfe18;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.d28c_rope_change_length_800d1130 0x800d1130 : { *(.text.d28c_rope_change_length_800d1130) }
  .rodata 0x803881b4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
