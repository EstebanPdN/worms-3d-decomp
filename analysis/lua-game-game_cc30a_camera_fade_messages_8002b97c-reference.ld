/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc30a_camera_fade_messages_8002b97c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc30a_call_8002aa48 = 0x8002aa48;
cc30a_call_8002bc14 = 0x8002bc14;
cc30a_call_8002bd88 = 0x8002bd88;
cc30a_call_8002c018 = 0x8002c018;
cc30a_call_8002c118 = 0x8002c118;
cc30a_call_8002c17c = 0x8002c17c;
cc30a_call_800a830c = 0x800a830c;
cc30a_call_800fc230 = 0x800fc230;
cc30a_call_8015f65c = 0x8015f65c;
cc30a_float_80372608 = 0x80372608;
cc30a_text_803725f4 = 0x803725f4;
SECTIONS {
  .text.cc30a_camera_fade_messages_8002b97c 0x8002b97c : { *(.text.cc30a_camera_fade_messages_8002b97c) }
  .sdata 0x804acc78 (NOLOAD) : {
    . = 0x0; cc30a_cache_804acc78 = .;
    . = 0x8; cc30a_cache_804acc80 = .;
    . = 0x30; cc30a_cache_804acca8 = .;
    . = 0x38; cc30a_cache_804accb0 = .;
    . = 0x40; cc30a_cache_804accb8 = .;
    . = 0x4b10; cc30a_global_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
