/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc29a_controller_messages_80023794)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc29a_base_8015fb34 = 0x8015fb34;
cc29a_clear_80024448 = 0x80024448;
cc29a_delay_80024990 = 0x80024990;
cc29a_equals_8015f65c = 0x8015f65c;
cc29a_read_80178c48 = 0x80178c48;
cc29a_refresh_800248f8 = 0x800248f8;
cc29a_set_80024844 = 0x80024844;
cc29a_start_80023944 = 0x80023944;
cc29a_stop_800243a4 = 0x800243a4;
cc29a_value_800a830c = 0x800a830c;
SECTIONS {
  .text.cc29a_controller_messages_80023794 0x80023794 : { *(.text.cc29a_controller_messages_80023794) }
  .sdata 0x804aca54 (NOLOAD) : {
    . = 0x0; cc29a_cache_804aca54 = .;
    . = 0x8; cc29a_cache_804aca5c = .;
    . = 0x10; cc29a_cache_804aca64 = .;
    . = 0x18; cc29a_cache_804aca6c = .;
    . = 0x20; cc29a_cache_804aca74 = .;
    . = 0x28; cc29a_cache_804aca7c = .;
    . = 0x30; cc29a_cache_804aca84 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
