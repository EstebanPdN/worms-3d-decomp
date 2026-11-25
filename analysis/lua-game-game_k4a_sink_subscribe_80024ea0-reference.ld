/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_sink_subscribe_80024ea0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_str_8036c7e8 = 0x8036c7e8;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.k4a_sink_subscribe_80024ea0 0x80024ea0 : { *(.text.k4a_sink_subscribe_80024ea0) }
  .sdata 0x804aca8c (NOLOAD) : {
    . = 0x0; w3d_message_804aca8c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
