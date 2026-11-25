/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_actor_settings_start_800d5d44)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_801613f0 = 0x801613f0;
as_a_80342a74 = 0x80342a74;
gravity_80388e2c = 0x80388e2c;
low_80388e34 = 0x80388e34;
member_query_80126308 = 0x80126308;
message_id_8015f5a0 = 0x8015f5a0;
msg_init_800c1620 = 0x800c1620;
place_800d5ff0 = 0x800d5ff0;
post_8016239c = 0x8016239c;
read_800fc1b0 = 0x800fc1b0;
subscribe_80162024 = 0x80162024;
water_80388e20 = 0x80388e20;
SECTIONS {
  .text.d24c_actor_settings_start_800d5d44 0x800d5d44 : { *(.text.d24c_actor_settings_start_800d5d44) }
  .sdata 0x804aea58 (NOLOAD) : {
    . = 0x0; c1_804aea58 = .;
    . = 0x8; c2_804aea60 = .;
    . = 0x10; c3_804aea68 = .;
    . = 0x20; c4_804aea78 = .;
    . = 0x2cfc; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
