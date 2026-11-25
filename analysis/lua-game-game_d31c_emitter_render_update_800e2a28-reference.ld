/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31c_emitter_render_update_800e2a28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
anim_800de4c4 = 0x800de4c4;
arena_801613f0 = 0x801613f0;
byte_80189504 = 0x80189504;
bytes_80189828 = 0x80189828;
cached_id_8015f5a0 = 0x8015f5a0;
cast_801797b4 = 0x801797b4;
cast_80342a78 = 0x80342a78;
colours_80189760 = 0x80189760;
constant_800e3434 = 0x800e3434;
empty_80341584 = 0x80341584;
empty_80342fa4 = 0x80342fa4;
empty_8040db38 = 0x8040db38;
flags_80189704 = 0x80189704;
lookup_80164fc8 = 0x80164fc8;
orient_800de40c = 0x800de40c;
positions_80189518 = 0x80189518;
post_8016239c = 0x8016239c;
pull_800dfe84 = 0x800dfe84;
rotations_80189574 = 0x80189574;
sizes_8018963c = 0x8018963c;
timed_800ddcbc = 0x800ddcbc;
value_80178d1c = 0x80178d1c;
vec_80178ec4 = 0x80178ec4;
SECTIONS {
  .text.d31c_emitter_render_update_800e2a28 0x800e2a28 : { *(.text.d31c_emitter_render_update_800e2a28) }
  .rodata 0x80389fcc : { *(.rodata) }
  .sdata 0x804aed14 (NOLOAD) : {
    . = 0x0; cache_804aed14 = .;
    . = 0x2a40; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
