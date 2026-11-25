/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_listener_subscribe_8002547c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_str_8036c84c = 0x8036c84c;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.k4a_listener_subscribe_8002547c 0x8002547c : { *(.text.k4a_listener_subscribe_8002547c) }
  .sdata 0x804aca9c (NOLOAD) : {
    . = 0x0; w3d_message_804aca9c = .;
    . = 0x10; w3d_message_804acaac = .;
    . = 0x18; w3d_message_804acab4 = .;
    . = 0x20; w3d_message_804acabc = .;
    . = 0x28; w3d_message_804acac4 = .;
    . = 0x30; w3d_message_804acacc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
