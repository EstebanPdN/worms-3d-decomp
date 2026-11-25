/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_powerbar_init_800f03a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
as_803426b4 = 0x803426b4;
as_80342a78 = 0x80342a78;
as_80342fa4 = 0x80342fa4;
as_mesh_8034380c = 0x8034380c;
bar_8038c1ec = 0x8038c1ec;
chat_8038c1e0 = 0x8038c1e0;
count_80178d1c = 0x80178d1c;
fill_8038c16c = 0x8038c16c;
half_8038c214 = 0x8038c214;
load_8015adf4 = 0x8015adf4;
max_8038c184 = 0x8038c184;
mesh_a_80189828 = 0x80189828;
mesh_alloc_8018920c = 0x8018920c;
mesh_b_80189884 = 0x80189884;
mesh_c_801898e0 = 0x801898e0;
mesh_colours_80189760 = 0x80189760;
mesh_flags_80189704 = 0x80189704;
mesh_set_80189450 = 0x80189450;
message_id_8015f5a0 = 0x8015f5a0;
next_8038c19c = 0x8038c19c;
one_8038c218 = 0x8038c218;
pos_8038c1b4 = 0x8038c1b4;
powerbar_8038c148 = 0x8038c148;
read_800fc1b0 = 0x800fc1b0;
read_800fc2f0 = 0x800fc2f0;
size_8038c1cc = 0x8038c1cc;
sound_8038c204 = 0x8038c204;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
subscribe_80162024 = 0x80162024;
value_80178ec4 = 0x80178ec4;
worm_8038c15c = 0x8038c15c;
SECTIONS {
  .text.d24c_powerbar_init_800f03a0 0x800f03a0 : { *(.text.d24c_powerbar_init_800f03a0) }
  .sdata 0x804af024 (NOLOAD) : {
    . = 0x0; colour_804af024 = .;
    . = 0x14; cache_804af038 = .;
    . = 0x1c; cache_804af040 = .;
    . = 0x24; cache_804af048 = .;
    . = 0x2c; cache_804af050 = .;
    . = 0x34; cache_804af058 = .;
    . = 0x2764; engine_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
