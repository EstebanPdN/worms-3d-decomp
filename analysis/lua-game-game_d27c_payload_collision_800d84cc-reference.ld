/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_payload_collision_800d84cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
finish_800ecb20 = 0x800ecb20;
fire_800d973c = 0x800d973c;
land_800d8b4c = 0x800d8b4c;
reset_800eba70 = 0x800eba70;
same_8015f65c = 0x8015f65c;
shoot_800ec6a8 = 0x800ec6a8;
sink_800ec1b4 = 0x800ec1b4;
water_800ebf80 = 0x800ebf80;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d27c_payload_collision_800d84cc 0x800d84cc : { *(.text.d27c_payload_collision_800d84cc) }
  .rodata 0x80389284 : { *(.rodata) }
  .sdata 0x804aeb00 (NOLOAD) : {
    . = 0x0; id_804aeb00 = .;
    . = 0x8; id_804aeb08 = .;
    . = 0x10; id_804aeb10 = .;
    . = 0x18; id_804aeb18 = .;
    . = 0x20; id_804aeb20 = .;
    . = 0x38; id_804aeb38 = .;
    . = 0x40; id_804aeb40 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
