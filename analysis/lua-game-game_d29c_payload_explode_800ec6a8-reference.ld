/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29c_payload_explode_800ec6a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
assert_80022e20 = 0x80022e20;
bomblets_800ebad8 = 0x800ebad8;
desc_801797b4 = 0x801797b4;
effect_800ed9c8 = 0x800ed9c8;
empty_80341584 = 0x80341584;
empty_8038b568 = 0x8038b568;
explode_800eca14 = 0x800eca14;
file_8038b4c4 = 0x8038b4c4;
missed_8038b588 = 0x8038b588;
msg_id_8015f5a0 = 0x8015f5a0;
over_800ecb20 = 0x800ecb20;
post_8015fc58 = 0x8015fc58;
remove_8015fd1c = 0x8015fd1c;
strcmp = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
temp_8038b56c = 0x8038b56c;
type_80361860 = 0x80361860;
type_803618f0 = 0x803618f0;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.d29c_payload_explode_800ec6a8 0x800ec6a8 : { *(.text.d29c_payload_explode_800ec6a8) }
  .sdata 0x804aef08 (NOLOAD) : {
    . = 0x0; id_804aef08 = .;
    . = 0x284c; heap_804b1754 = .;
    . = 0x2880; scene_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
