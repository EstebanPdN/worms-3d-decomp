/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27k_net_message_8021a768)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__15String_803426b8 = 0x803426b8;
alloc_801613f0 = 0x801613f0;
base_8015fd1c = 0x8015fd1c;
context_80165254 = 0x80165254;
dispatch_8021c294 = 0x8021c294;
empty_8021b0a8 = 0x8021b0a8;
equals_8015f620 = 0x8015f620;
key_8041a9a8 = 0x8041a9a8;
lookup_8020b680 = 0x8020b680;
msgid_8015f5a0 = 0x8015f5a0;
other_8021a704 = 0x8021a704;
post_8016239c = 0x8016239c;
props_80240b84 = 0x80240b84;
reset_8015cbe0 = 0x8015cbe0;
same_8015f65c = 0x8015f65c;
send_8021e930 = 0x8021e930;
stamp_80162ba8 = 0x80162ba8;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
table_8040db38 = 0x8040db38;
title_80165018 = 0x80165018;
value_8021eb00 = 0x8021eb00;
SECTIONS {
  .text.w3d_d27k_net_message_8021a768 0x8021a768 : { *(.text.w3d_d27k_net_message_8021a768) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; global_804aac54 = .;
    . = 0x2f4; global_804aaf48 = .;
    . = 0x5ab8; cache_804b070c = .;
    . = 0x5ac8; cache_804b071c = .;
    . = 0x5ad0; cache_804b0724 = .;
    . = 0x5ae0; cache_804b0734 = .;
    . = 0x5b00; cache_804b0754 = .;
    . = 0x5b18; cache_804b076c = .;
    . = 0x5b20; cache_804b0774 = .;
    . = 0x5b30; cache_804b0784 = .;
    . = 0x6b00; global_804b1754 = .;
    . = 0x6b34; global_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
