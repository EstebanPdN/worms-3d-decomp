/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27k_team_stream_ready_8021b8c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
active_8021ec2c = 0x8021ec2c;
alloc_801613f0 = 0x801613f0;
erase_800c56b8 = 0x800c56b8;
msgid_8015f5a0 = 0x8015f5a0;
object_80240994 = 0x80240994;
post_8016239c = 0x8016239c;
read_8021bb9c = 0x8021bb9c;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
table_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d27k_team_stream_ready_8021b8c0 0x8021b8c0 : { *(.text.w3d_d27k_team_stream_ready_8021b8c0) }
  .sdata 0x804b06e4 (NOLOAD) : {
    . = 0x0; cache_804b06e4 = .;
    . = 0x40; cache_804b0724 = .;
    . = 0x58; cache_804b073c = .;
    . = 0x1070; global_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
