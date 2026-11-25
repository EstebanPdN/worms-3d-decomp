/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_particle_emitter_start_800e3e8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
arena_801613f0 = 0x801613f0;
array_new_801fe220 = 0x801fe220;
assert_80022e20 = 0x80022e20;
ball_8038a050 = 0x8038a050;
file_8038a074 = 0x8038a074;
handle_ctor_801261bc = 0x801261bc;
handle_query_80126308 = 0x80126308;
heap_alloc_802098d8 = 0x802098d8;
identity_80341584 = 0x80341584;
load_8015adf4 = 0x8015adf4;
memset = 0x802eefe0;
message_id_8015f5a0 = 0x8015f5a0;
message_init_800c1620 = 0x800c1620;
message_post_8016239c = 0x8016239c;
settings_801797b4 = 0x801797b4;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
sub_init_800dec8c = 0x800dec8c;
subscribe_80162024 = 0x80162024;
title_8038a060 = 0x8038a060;
type_80361860 = 0x80361860;
type_803618f0 = 0x803618f0;
zero_8038a094 = 0x8038a094;
SECTIONS {
  .text.d24c_particle_emitter_start_800e3e8c 0x800e3e8c : { *(.text.d24c_particle_emitter_start_800e3e8c) }
  .sdata 0x804aed44 (NOLOAD) : {
    . = 0x0; cache_804aed44 = .;
    . = 0x8; cache_804aed4c = .;
    . = 0x28; cache_804aed6c = .;
    . = 0x878; pool_804af5bc = .;
    . = 0x2a10; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
