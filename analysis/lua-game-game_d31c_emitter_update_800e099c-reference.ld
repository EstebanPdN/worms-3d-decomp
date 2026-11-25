/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31c_emitter_update_800e099c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
apply_80122580 = 0x80122580;
arena_801613f0 = 0x801613f0;
byte_80189504 = 0x80189504;
bytes_80189828 = 0x80189828;
cached_id_8015f5a0 = 0x8015f5a0;
cast_801797b4 = 0x801797b4;
class_803613b0 = 0x803613b0;
colours_80189760 = 0x80189760;
empty_80341584 = 0x80341584;
empty_8040db38 = 0x8040db38;
fire_800e1268 = 0x800e1268;
flags_80189704 = 0x80189704;
holder_800dfdf4 = 0x800dfdf4;
kill_800e1f40 = 0x800e1f40;
lifetime_800e1e68 = 0x800e1e68;
lookup_80164fc8 = 0x80164fc8;
positions_80189518 = 0x80189518;
post_8016239c = 0x8016239c;
query_800e25dc = 0x800e25dc;
remove_8015fd1c = 0x8015fd1c;
rotations_80189574 = 0x80189574;
sizes_8018963c = 0x8018963c;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
sweep_800df570 = 0x800df570;
SECTIONS {
  .text.d31c_emitter_update_800e099c 0x800e099c : { *(.text.d31c_emitter_update_800e099c) }
  .rodata 0x80389db4 : { *(.rodata) }
  .sdata 0x804aecf8 (NOLOAD) : {
    . = 0x0; cache_804aecf8 = .;
    . = 0x2a5c; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
