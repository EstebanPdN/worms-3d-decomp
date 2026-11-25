/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40i_emitter_activate_801074f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
acquire_80162024 = 0x80162024;
activate_800dca14 = 0x800dca14;
arena_801613f0 = 0x801613f0;
as_table_80341584 = 0x80341584;
cast_8034380c = 0x8034380c;
class_80410398 = 0x80410398;
colours_80189760 = 0x80189760;
context_80165254 = 0x80165254;
create_8020b680 = 0x8020b680;
expand_80107ccc = 0x80107ccc;
flags_80189704 = 0x80189704;
inner_801797b4 = 0x801797b4;
message_id_8015f5a0 = 0x8015f5a0;
normalize_801f6c2c = 0x801f6c2c;
post_8016239c = 0x8016239c;
pot_800e58fc = 0x800e58fc;
resize_8018920c = 0x8018920c;
set_name_8015adf4 = 0x8015adf4;
spawn_80164514 = 0x80164514;
start_800ddcbc = 0x800ddcbc;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
uvs_8018963c = 0x8018963c;
vt_8040db38 = 0x8040db38;
wrap_80107ab8 = 0x80107ab8;
SECTIONS {
  .text.d40i_emitter_activate_801074f0 0x801074f0 : { *(.text.d40i_emitter_activate_801074f0) }
  .rodata 0x80399af4 : { *(.rodata) }
  .sdata 0x804aaecc (NOLOAD) : {
    . = 0x0; pot_804aaecc = .;
    . = 0x4354; id_804af220 = .;
    . = 0x4364; id_804af230 = .;
    . = 0x6888; arena_804b1754 = .;
    . = 0x68bc; service_804b1788 = .;
    . = 0x68c0; spawn_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
