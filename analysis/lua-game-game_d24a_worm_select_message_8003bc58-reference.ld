/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24a_worm_select_message_8003bc58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_apply_8003d0a0 = 0x8003d0a0;
w3d_base_handler_8015fb34 = 0x8015fb34;
w3d_engine_context_80165254 = 0x80165254;
w3d_finish_8015fd1c = 0x8015fd1c;
w3d_message_id_equals_8015f65c = 0x8015f65c;
w3d_refresh_8003ce0c = 0x8003ce0c;
w3d_select_8003bf70 = 0x8003bf70;
w3d_start_8003c0f0 = 0x8003c0f0;
w3d_stop_8003c364 = 0x8003c364;
w3d_update_8003cdcc = 0x8003cdcc;
SECTIONS {
  .text.w3d_d24a_worm_select_message_8003bc58 0x8003bc58 : { *(.text.w3d_d24a_worm_select_message_8003bc58) }
  .sdata 0x804ad138 (NOLOAD) : {
    . = 0x0; w3d_message_804ad138 = .;
    . = 0x8; w3d_message_804ad140 = .;
    . = 0x10; w3d_message_804ad148 = .;
    . = 0x18; w3d_message_804ad150 = .;
    . = 0x20; w3d_message_804ad158 = .;
    . = 0x28; w3d_message_804ad160 = .;
    . = 0x30; w3d_message_804ad168 = .;
    . = 0x38; w3d_message_804ad170 = .;
    . = 0x40; w3d_message_804ad178 = .;
    . = 0x48; w3d_message_804ad180 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
