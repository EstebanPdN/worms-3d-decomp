/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28h_baseball_bat_fire_800c3a18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
ammo_800fc6dc = 0x800fc6dc;
as_803426b4 = 0x803426b4;
ctor_8004ee4c = 0x8004ee4c;
melee_8004c2f0 = 0x8004c2f0;
object_80164fc8 = 0x80164fc8;
post_8016239c = 0x8016239c;
show_800fdc80 = 0x800fdc80;
sound_800e5ca4 = 0x800e5ca4;
strcmp = 0x802ef234;
type_803600c0 = 0x803600c0;
value_80178c48 = 0x80178c48;
worm_8003f240 = 0x8003f240;
SECTIONS {
  .text.d28h_baseball_bat_fire_800c3a18 0x800c3a18 : { *(.text.d28h_baseball_bat_fire_800c3a18) }
  .rodata 0x80383290 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; g_turn_804aa95e = .;
    . = 0x6df6; g_arena_804b1754 = .;
    . = 0x6e2a; g_world_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
