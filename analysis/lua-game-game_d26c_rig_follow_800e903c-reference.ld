/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_rig_follow_800e903c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
angles_800e9204 = 0x800e9204;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
one_8038b244 = 0x8038b244;
spin_800e9678 = 0x800e9678;
SECTIONS {
  .text.d26c_rig_follow_800e903c 0x800e903c : { *(.text.d26c_rig_follow_800e903c) }
  .rodata 0x8038b248 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
