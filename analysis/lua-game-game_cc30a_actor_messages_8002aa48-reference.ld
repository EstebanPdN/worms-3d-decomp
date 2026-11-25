/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc30a_actor_messages_8002aa48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc30a_call_8002aba4 = 0x8002aba4;
cc30a_call_8002acd0 = 0x8002acd0;
cc30a_call_8002b0a0 = 0x8002b0a0;
cc30a_call_8015f5a0 = 0x8015f5a0;
cc30a_call_8015f65c = 0x8015f65c;
cc30a_call_8015fb34 = 0x8015fb34;
cc30a_call_801613f0 = 0x801613f0;
cc30a_call_8016239c = 0x8016239c;
cc30a_type_8040db38 = 0x8040db38;
SECTIONS {
  .text.cc30a_actor_messages_8002aa48 0x8002aa48 : { *(.text.cc30a_actor_messages_8002aa48) }
  .sdata 0x804acc34 (NOLOAD) : {
    . = 0x0; cc30a_cache_804acc34 = .;
    . = 0x10; cc30a_cache_804acc44 = .;
    . = 0x18; cc30a_cache_804acc4c = .;
    . = 0x28; cc30a_cache_804acc5c = .;
    . = 0x4b20; cc30a_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
