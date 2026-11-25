/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(codex_flags_8006ee18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
t261_check_8006ae58 = 0x8006ae58;
t261_handles_8006e10c = 0x8006e10c;
SECTIONS {
  .text.codex_flags_8006ee18 0x8006ee18 : { *(.text.codex_flags_8006ee18) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; t261_state_804aaabc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
