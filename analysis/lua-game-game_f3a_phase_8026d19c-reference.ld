/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f3a_phase_8026d19c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
limit_803cbd08 = 0x803cbd08;
offset_803cbd14 = 0x803cbd14;
reset_803cbd0c = 0x803cbd0c;
step_803cbd04 = 0x803cbd04;
zero_803cbd10 = 0x803cbd10;
SECTIONS {
  .text.w3d_f3a_phase_8026d19c 0x8026d19c : { *(.text.w3d_f3a_phase_8026d19c) }
  .sdata 0x804abb80 (NOLOAD) : {
    . = 0x0; phase_804abb80 = .;
    . = 0x4; phase_804abb84 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
