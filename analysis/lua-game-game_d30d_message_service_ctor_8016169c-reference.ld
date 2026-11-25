/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30d_message_service_ctor_8016169c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__builtin_vec_new = 0x801fe220;
alloc_80212fd4 = 0x80212fd4;
base_801628b0 = 0x801628b0;
block_init_801626c8 = 0x801626c8;
blocks_80455244 = 0x80455244;
free_802134fc = 0x802134fc;
memcpy = 0x802eee50;
memmove = 0x802eeef4;
name1_803a48b0 = 0x803a48b0;
name2_803a48c0 = 0x803a48c0;
read_int_80206920 = 0x80206920;
vt_804117c8 = 0x804117c8;
vt_804117f8 = 0x804117f8;
SECTIONS {
  .text.d30d_message_service_ctor_8016169c 0x8016169c : { *(.text.d30d_message_service_ctor_8016169c) }
  .sdata 0x804ab498 (NOLOAD) : {
    . = 0x0; maxInterests_804ab498 = .;
    . = 0x4; maxMessages_804ab49c = .;
    . = 0x8; self_804ab4a0 = .;
    . = 0xc; table_804ab4a4 = .;
    . = 0x10; pool_804ab4a8 = .;
    . = 0x14; s0_804ab4ac = .;
    . = 0x18; s1_804ab4b0 = .;
    . = 0x1c; s2_804ab4b4 = .;
    . = 0x20; s3_804ab4b8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
