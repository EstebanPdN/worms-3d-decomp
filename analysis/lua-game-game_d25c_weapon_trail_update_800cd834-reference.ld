/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25c_weapon_trail_update_800cd834)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4NamePCc = 0x8020bb54;
at_800d0f74 = 0x800d0f74;
count_800d0f54 = 0x800d0f54;
create_80164514 = 0x80164514;
forward_8020b680 = 0x8020b680;
init_801222cc = 0x801222cc;
key_80410b08 = 0x80410b08;
lookup_80164fc8 = 0x80164fc8;
seg_80122800 = 0x80122800;
spawn_800ccc14 = 0x800ccc14;
SECTIONS {
  .text.d25c_weapon_trail_update_800cd834 0x800cd834 : { *(.text.d25c_weapon_trail_update_800cd834) }
  .rodata 0x80387e4c : { *(.rodata) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; graphics_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
