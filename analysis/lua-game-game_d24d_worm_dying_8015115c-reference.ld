/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_worm_dying_8015115c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_after_death_801506f8 = 0x801506f8;
d24d_class_a_80361860 = 0x80361860;
d24d_class_c_803618f0 = 0x803618f0;
d24d_create_slot_80022e20 = 0x80022e20;
d24d_engine_80165254 = 0x80165254;
d24d_logic_entity_803a0e2c = 0x803a0e2c;
d24d_random_unit_801610a0 = 0x801610a0;
d24d_sender_of_801190d0 = 0x801190d0;
d24d_set_motion_801492ec = 0x801492ec;
d24d_worm_dying_803a1888 = 0x803a1888;
SECTIONS {
  .text.d24d_worm_dying_8015115c 0x8015115c : { *(.text.d24d_worm_dying_8015115c) }
  .rodata 0x803a1894 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
