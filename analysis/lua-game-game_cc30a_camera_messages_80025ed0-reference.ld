/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc30a_camera_messages_80025ed0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc30a_call_80026064 = 0x80026064;
cc30a_call_80026288 = 0x80026288;
cc30a_call_800267a4 = 0x800267a4;
cc30a_call_800fc230 = 0x800fc230;
cc30a_call_8015f65c = 0x8015f65c;
cc30a_call_8015fb34 = 0x8015fb34;
cc30a_text_8036c9b8 = 0x8036c9b8;
SECTIONS {
  .text.cc30a_camera_messages_80025ed0 0x80025ed0 : { *(.text.cc30a_camera_messages_80025ed0) }
  .sdata 0x804acaf4 (NOLOAD) : {
    . = 0x0; cc30a_cache_804acaf4 = .;
    . = 0x8; cc30a_cache_804acafc = .;
    . = 0x20; cc30a_cache_804acb14 = .;
    . = 0x4c94; cc30a_global_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
