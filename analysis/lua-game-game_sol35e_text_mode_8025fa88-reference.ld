/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35e_text_mode_8025fa88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35e_base_mode_802b0990 = 0x802b0990;
sol35e_dispatch_payload_802b1258 = 0x802b1258;
sol35e_fill_colour_8018d35c = 0x8018d35c;
sol35e_mesh_identity_80343580 = 0x80343580;
sol35e_update_controls_80260144 = 0x80260144;
SECTIONS {
  .text.sol35e_text_mode_8025fa88 0x8025fa88 : { *(.text.sol35e_text_mode_8025fa88) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
