/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32c_emitter_setup_800e1420)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
array_alloc_801fe220 = 0x801fe220;
array_free_801fe240 = 0x801fe240;
as_mesh_8034380c = 0x8034380c;
as_sink_80343584 = 0x80343584;
attach_80164514 = 0x80164514;
cached_id_8015f5a0 = 0x8015f5a0;
cast_801797b4 = 0x801797b4;
cleanup_800e1cbc = 0x800e1cbc;
create_8020b680 = 0x8020b680;
empty_80341584 = 0x80341584;
empty_80342a74 = 0x80342a74;
flags_80189704 = 0x80189704;
init_800dec8c = 0x800dec8c;
load_8015adf4 = 0x8015adf4;
named_8015ae3c = 0x8015ae3c;
random_8015ff5c = 0x8015ff5c;
read_setting_800fc1b0 = 0x800fc1b0;
remove_8015fd1c = 0x8015fd1c;
resize_8018920c = 0x8018920c;
s_payload_80389dd0 = 0x80389dd0;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
subscribe_80162024 = 0x80162024;
trail_init_801222cc = 0x801222cc;
type_80410b08 = 0x80410b08;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.d32c_emitter_setup_800e1420 0x800e1420 : { *(.text.d32c_emitter_setup_800e1420) }
  .rodata 0x80389eb8 : { *(.rodata) }
  .sdata 0x804aaecc (NOLOAD) : {
    . = 0x0; global_804aaecc = .;
    . = 0x3e14; c_804aece0 = .;
    . = 0x3e1c; c_804aece8 = .;
    . = 0x3e24; c_804aecf0 = .;
    . = 0x3e34; c_804aed00 = .;
    . = 0x68bc; manager_804b1788 = .;
    . = 0x68c0; world_804b178c = .;
    . = 0x6920; display_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
