/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25a_binoculars_start_8002b544)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
w3d_handle_load_8015adf4 = 0x8015adf4;
w3d_string_803725a0 = 0x803725a0;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d25a_binoculars_start_8002b544 0x8002b544 : { *(.text.w3d_d25a_binoculars_start_8002b544) }
  .rodata 0x803725b0 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_game_state_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
