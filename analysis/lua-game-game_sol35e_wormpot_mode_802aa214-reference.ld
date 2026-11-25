/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35e_wormpot_mode_802aa214)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_pot_mode_helper_802b0990 = 0x802b0990;
w3d_pot_payload_notify_802b1258 = 0x802b1258;
w3d_s4_wormpot_start = 0x802aa33c;
w3d_s4_wormpot_stop = 0x802aa3a4;
SECTIONS {
  .text.sol35e_wormpot_mode_802aa214 0x802aa214 : { *(.text.sol35e_wormpot_mode_802aa214) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
