/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24a_airstrike_message_8002e9f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_base_handler_8015fb34 = 0x8015fb34;
w3d_engine_context_80165254 = 0x80165254;
w3d_finish_8015fd1c = 0x8015fd1c;
w3d_message_id_equals_8015f65c = 0x8015f65c;
w3d_notify_800fde64 = 0x800fde64;
w3d_set_time_8002f3d4 = 0x8002f3d4;
w3d_start_8002ead8 = 0x8002ead8;
w3d_stop_8002f354 = 0x8002f354;
SECTIONS {
  .text.w3d_d24a_airstrike_message_8002e9f0 0x8002e9f0 : { *(.text.w3d_d24a_airstrike_message_8002e9f0) }
  .sdata 0x804acd2c (NOLOAD) : {
    . = 0x0; w3d_message_804acd2c = .;
    . = 0x8; w3d_message_804acd34 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
