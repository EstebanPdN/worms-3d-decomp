/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc31a_camera_restore_modes_8002d3e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc31a_call_8010a8e0 = 0x8010a8e0;
cc31a_call_8015a6b8 = 0x8015a6b8;
cc31a_call_8015f5a0 = 0x8015f5a0;
cc31a_call_801613f0 = 0x801613f0;
cc31a_call_8016239c = 0x8016239c;
cc31a_text_8037296c = 0x8037296c;
cc31a_text_80372974 = 0x80372974;
cc31a_text_80372984 = 0x80372984;
cc31a_text_8037298c = 0x8037298c;
cc31a_text_803729a4 = 0x803729a4;
cc31a_text_803729b0 = 0x803729b0;
cc31a_text_803729bc = 0x803729bc;
cc31a_text_803729c8 = 0x803729c8;
cc31a_text_803729d8 = 0x803729d8;
SECTIONS {
  .text.cc31a_camera_restore_modes_8002d3e4 0x8002d3e4 : { *(.text.cc31a_camera_restore_modes_8002d3e4) }
  .sdata 0x804accd4 (NOLOAD) : {
    . = 0x0; cc31a_cache_804accd4 = .;
    . = 0x8; cc31a_cache_804accdc = .;
    . = 0x4a80; cc31a_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
