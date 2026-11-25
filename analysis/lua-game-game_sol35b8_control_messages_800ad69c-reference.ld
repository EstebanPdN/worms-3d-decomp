/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b8_control_messages_800ad69c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b8_control_allocate_801613f0 = 0x801613f0;
sol35b8_control_id_8015f5a0 = 0x8015f5a0;
sol35b8_control_post_8016239c = 0x8016239c;
sol35b8_control_query_8015a6b8 = 0x8015a6b8;
sol35b8_control_string_8010a8e0 = 0x8010a8e0;
sol35b8_control_text_8038200c = 0x8038200c;
sol35b8_control_text_80382018 = 0x80382018;
sol35b8_control_text_80382028 = 0x80382028;
sol35b8_control_text_80382040 = 0x80382040;
sol35b8_control_text_80382050 = 0x80382050;
sol35b8_control_text_8038205c = 0x8038205c;
sol35b8_control_text_80382068 = 0x80382068;
SECTIONS {
  .text.sol35b8_control_messages_800ad69c 0x800ad69c : { *(.text.sol35b8_control_messages_800ad69c) }
  .sdata 0x804ae3c8 (NOLOAD) : {
    . = 0x0; sol35b8_control_cache_804ae3c8 = .;
    . = 0x8; sol35b8_control_cache_804ae3d0 = .;
    . = 0x338c; sol35b8_control_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
