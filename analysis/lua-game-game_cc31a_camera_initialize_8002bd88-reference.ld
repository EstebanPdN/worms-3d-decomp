/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc31a_camera_initialize_8002bd88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc31a_call_800c1620 = 0x800c1620;
cc31a_call_800fc230 = 0x800fc230;
cc31a_call_800fc4c8 = 0x800fc4c8;
cc31a_call_801190b4 = 0x801190b4;
cc31a_call_8015f5a0 = 0x8015f5a0;
cc31a_call_801613f0 = 0x801613f0;
cc31a_call_80162024 = 0x80162024;
cc31a_call_8016239c = 0x8016239c;
cc31a_float_80372634 = 0x80372634;
cc31a_float_80372638 = 0x80372638;
cc31a_text_803725f4 = 0x803725f4;
cc31a_text_8037260c = 0x8037260c;
cc31a_text_80372620 = 0x80372620;
cc31a_type_8040db38 = 0x8040db38;
SECTIONS {
  .text.cc31a_camera_initialize_8002bd88 0x8002bd88 : { *(.text.cc31a_camera_initialize_8002bd88) }
  .sdata 0x804acc78 (NOLOAD) : {
    . = 0x0; cc31a_cache_804acc78 = .;
    . = 0x8; cc31a_cache_804acc80 = .;
    . = 0x10; cc31a_cache_804acc88 = .;
    . = 0x20; cc31a_cache_804acc98 = .;
    . = 0x28; cc31a_cache_804acca0 = .;
    . = 0x30; cc31a_cache_804acca8 = .;
    . = 0x38; cc31a_cache_804accb0 = .;
    . = 0x40; cc31a_cache_804accb8 = .;
    . = 0x4adc; cc31a_arena_804b1754 = .;
    . = 0x4b10; cc31a_global_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
