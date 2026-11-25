/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27k_connection_closed_8021bd4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
erase_800c56b8 = 0x800c56b8;
leave_801298cc = 0x801298cc;
msgid_8015f5a0 = 0x8015f5a0;
msgint_800a82f0 = 0x800a82f0;
object_80240994 = 0x80240994;
paused_8015ccbc = 0x8015ccbc;
post_8016239c = 0x8016239c;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
table_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d27k_connection_closed_8021bd4c 0x8021bd4c : { *(.text.w3d_d27k_connection_closed_8021bd4c) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; global_804aac54 = .;
    . = 0x2f4; global_804aaf48 = .;
    . = 0xe60; global_804abab4 = .;
    . = 0x5a88; cache_804b06dc = .;
    . = 0x5ac0; cache_804b0714 = .;
    . = 0x5b38; cache_804b078c = .;
    . = 0x6b00; global_804b1754 = .;
    . = 0x6b34; global_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
