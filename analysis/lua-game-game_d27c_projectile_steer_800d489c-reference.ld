/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_projectile_steer_800d489c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
lead_80388d24 = 0x80388d24;
query_800b0788 = 0x800b0788;
sqrt_802e82c0 = 0x802e82c0;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d27c_projectile_steer_800d489c 0x800d489c : { *(.text.d27c_projectile_steer_800d489c) }
  .rodata 0x80388d28 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; traceFrac_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
