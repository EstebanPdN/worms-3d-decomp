/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol32c_dispatch_typed_entries_802bdd24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol32c_clear_entries_802bf658 = 0x802bf658;
sol32c_dispatch_first_802bdf10 = 0x802bdf10;
sol32c_dispatch_second_802be9e4 = 0x802be9e4;
sol32c_dispatch_third_802c00dc = 0x802c00dc;
sol32c_first_type_80366258 = 0x80366258;
sol32c_position_bias_803d83a8 = 0x803d83a8;
sol32c_refresh_entries_802bf81c = 0x802bf81c;
sol32c_resource_identity_80341584 = 0x80341584;
sol32c_resource_owner_801797b4 = 0x801797b4;
sol32c_second_type_803662f8 = 0x803662f8;
sol32c_third_type_803662a8 = 0x803662a8;
SECTIONS {
  .text.sol32c_dispatch_typed_entries_802bdd24 0x802bdd24 : { *(.text.sol32c_dispatch_typed_entries_802bdd24) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
