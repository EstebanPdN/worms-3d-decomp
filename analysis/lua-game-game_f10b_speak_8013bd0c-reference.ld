/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f10b_speak_8013bd0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
actor_800fc6dc = 0x800fc6dc;
append_8020bf2c = 0x8020bf2c;
blocked_8013f884 = 0x8013f884;
compare_802ef234 = 0x802ef234;
finish_8020c5c4 = 0x8020c5c4;
header_80341884 = 0x80341884;
init_8020c5c0 = 0x8020c5c0;
option_800fc230 = 0x800fc230;
release_80341588 = 0x80341588;
separator_8039f884 = 0x8039f884;
special0_8039f87c = 0x8039f87c;
special1_8039f880 = 0x8039f880;
voices_8039f824 = 0x8039f824;
SECTIONS {
  .text.f10b_speak_8013bd0c 0x8013bd0c : { *(.text.f10b_speak_8013bd0c) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
