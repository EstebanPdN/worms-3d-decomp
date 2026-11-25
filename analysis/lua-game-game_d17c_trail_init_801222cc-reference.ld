/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d17c_trail_init_801222cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d17c_String_8020bb54PCc = 0x8020bb54;
d17c_as_mesh_8034357c = 0x8034357c;
d17c_handle_load_8015adf4 = 0x8015adf4;
d17c_mesh_shape_80174074 = 0x80174074;
d17c_short_trail_8039b7d4 = 0x8039b7d4;
d17c_string_finish_8020c5c4 = 0x8020c5c4;
d17c_string_release_80341588 = 0x80341588;
d17c_trail_8039b7e0 = 0x8039b7e0;
d17c_vec3_zero_8045e788 = 0x8045e788;
memset = 0x802eefe0;
SECTIONS {
  .text.d17c_trail_init_801222cc 0x801222cc : { *(.text.d17c_trail_init_801222cc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
