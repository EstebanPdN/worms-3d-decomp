/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_rain_loop_start_800f18bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_cached_message_id = 0x8015f5a0;
w3d_engine_get_context = 0x80165254;
w3d_f32_8038c3e0 = 0x8038c3e0;
w3d_str_8038c3d4 = 0x8038c3d4;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.k4a_rain_loop_start_800f18bc 0x800f18bc : { *(.text.k4a_rain_loop_start_800f18bc) }
  .sdata 0x804af098 (NOLOAD) : {
    . = 0x0; w3d_message_804af098 = .;
    . = 0x26f0; w3d_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
