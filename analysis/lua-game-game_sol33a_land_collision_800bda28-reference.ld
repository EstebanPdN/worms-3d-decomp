/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol33a_land_collision_800bda28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol33a_cast_80342a78 = 0x80342a78;
sol33a_collide_800b17c4 = 0x800b17c4;
sol33a_groups_8043bb64 = 0x8043bb64;
sol33a_landAllocate_801613f0 = 0x801613f0;
sol33a_landMessage_800b92a4 = 0x800b92a4;
sol33a_landPost_8016239c = 0x8016239c;
sol33a_mask_800bd53c = 0x800bd53c;
sol33a_position_80066894 = 0x80066894;
sol33a_property_800fc230 = 0x800fc230;
sol33a_radius_800668ec = 0x800668ec;
sol33a_read_80178d1c = 0x80178d1c;
sol33a_write_80178d28 = 0x80178d28;
SECTIONS {
  .text.sol33a_land_collision_800bda28 0x800bda28 : { *(.text.sol33a_land_collision_800bda28) }
  .rodata 0x80382b7c : { *(.rodata) }
  .sdata 0x804ae5dc (NOLOAD) : {
    . = 0x0; sol33a_destroyed_804ae5dc = .;
    . = 0x3178; sol33a_landAllocator_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
