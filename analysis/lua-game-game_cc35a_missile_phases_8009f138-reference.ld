/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc35a_missile_phases_8009f138)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc35a_context_80341584 = 0x80341584;
cc35a_finish_800ec6a8 = 0x800ec6a8;
cc35a_sound_803806e0 = 0x803806e0;
cc35a_timing_801797b4 = 0x801797b4;
cc35a_zero_803806f4 = 0x803806f4;
SECTIONS {
  .text.cc35a_missile_phases_8009f138 0x8009f138 : { *(.text.cc35a_missile_phases_8009f138) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; cc35a_service_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
