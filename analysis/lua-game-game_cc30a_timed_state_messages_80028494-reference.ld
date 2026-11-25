/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc30a_timed_state_messages_80028494)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc30a_call_80028708 = 0x80028708;
cc30a_call_8015f620 = 0x8015f620;
cc30a_call_8015f65c = 0x8015f65c;
cc30a_call_8015fb34 = 0x8015fb34;
cc30a_call_8015fd14 = 0x8015fd14;
SECTIONS {
  .text.cc30a_timed_state_messages_80028494 0x80028494 : { *(.text.cc30a_timed_state_messages_80028494) }
  .sdata 0x804acbdc (NOLOAD) : {
    . = 0x0; cc30a_cache_804acbdc = .;
    . = 0x8; cc30a_cache_804acbe4 = .;
    . = 0x10; cc30a_cache_804acbec = .;
    . = 0x18; cc30a_cache_804acbf4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
