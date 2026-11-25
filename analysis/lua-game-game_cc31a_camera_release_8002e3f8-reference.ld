/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc31a_camera_release_8002e3f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc31a_call_80125fdc = 0x80125fdc;
cc31a_call_801265a4 = 0x801265a4;
cc31a_call_8015f5a0 = 0x8015f5a0;
cc31a_call_801613f0 = 0x801613f0;
cc31a_call_8016239c = 0x8016239c;
cc31a_type_8040db38 = 0x8040db38;
SECTIONS {
  .text.cc31a_camera_release_8002e3f8 0x8002e3f8 : { *(.text.cc31a_camera_release_8002e3f8) }
  .sdata 0x804acd18 (NOLOAD) : {
    . = 0x0; cc31a_cache_804acd18 = .;
    . = 0x8; cc31a_cache_804acd20 = .;
    . = 0x4a3c; cc31a_arena_804b1754 = .;
    . = 0x4a70; cc31a_global_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
