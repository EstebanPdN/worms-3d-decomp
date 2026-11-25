/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_jetpack_update_8014d7c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_blocked_801418c4 = 0x801418c4;
d24d_can_stop_80146b84 = 0x80146b84;
d24d_class_a_80361860 = 0x80361860;
d24d_class_c_803618f0 = 0x803618f0;
d24d_component_8014c89c = 0x8014c89c;
d24d_create_slot_80022e20 = 0x80022e20;
d24d_direction_of__FP16d24d_JetpackWorm = 0x8014c260;
d24d_jet_offset__FP12d24d_JetpackP9d24d_Vec3T1 = 0x800aa628;
d24d_jet_place_800abbb4 = 0x800abbb4;
d24d_jet_velocity__FP12d24d_JetpackP9d24d_Vec3T1f = 0x800aabbc;
d24d_jetpack_active_803a1658 = 0x803a1658;
d24d_logic_entity_803a0e2c = 0x803a0e2c;
d24d_lookup_80164fc8 = 0x80164fc8;
d24d_set_thrust_off_800ac14c = 0x800ac14c;
SECTIONS {
  .text.d24d_jetpack_update_8014d7c8 0x8014d7c8 : { *(.text.d24d_jetpack_update_8014d7c8) }
  .rodata 0x803a166c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
