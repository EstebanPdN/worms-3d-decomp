/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(update__5ActorfPC5Input)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cast_801797b4 = 0x801797b4;
cos_802e86d4 = 0x802e86d4;
ease_800d4734 = 0x800d4734;
ease_800d47f0 = 0x800d47f0;
empty_80341584 = 0x80341584;
ledge_800d4b90 = 0x800d4b90;
middle_8043ae20 = 0x8043ae20;
muzzle_800d4e3c = 0x800d4e3c;
probe_800d3e5c = 0x800d3e5c;
seen_80440e1c = 0x80440e1c;
sin_802e88ac = 0x802e88ac;
sqrt_802e82c0 = 0x802e82c0;
steer_800d489c = 0x800d489c;
trace_800b0788 = 0x800b0788;
SECTIONS {
  .text.update__5ActorfPC5Input 0x800d3208 : { *(.text.update__5ActorfPC5Input) }
  .rodata 0x80388cc8 : { *(.rodata) }
  .sdata 0x804ae9e8 (NOLOAD) : {
    . = 0x0; guard_804ae9e8 = .;
    . = 0x2d7c; hit_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
