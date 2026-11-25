/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26h_jetpack_graphics_init_800ade2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
arena_alloc_801613f0 = 0x801613f0;
as_float_80342a74 = 0x80342a74;
lookup_800fc1b0 = 0x800fc1b0;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
target_init_801190b4 = 0x801190b4;
w3d_handle_load_8015adf4 = 0x8015adf4;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d26h_jetpack_graphics_init_800ade2c 0x800ade2c : { *(.text.d26h_jetpack_graphics_init_800ade2c) }
  .rodata 0x80382100 : { *(.rodata) }
  .sdata 0x804aac84 (NOLOAD) : {
    . = 0x0; g_804aac84 = .;
    . = 0x4; g_804aac88 = .;
    . = 0x3758; id_804ae3dc = .;
    . = 0x6ad0; g_arena_804b1754 = .;
    . = 0x6b04; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
