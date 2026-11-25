/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19c_intro_fade_80126884)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d19c_String_8020bb54PCc = 0x8020bb54;
d19c_as_mesh_8034357c = 0x8034357c;
d19c_handle_load_8015adf4 = 0x8015adf4;
d19c_mesh_set_colour_80173df0 = 0x80173df0;
d19c_scope_enter_8015aee8 = 0x8015aee8;
d19c_string_finish_8020c5c4 = 0x8020c5c4;
d19c_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d19c_intro_fade_80126884 0x80126884 : { *(.text.d19c_intro_fade_80126884) }
  .rodata 0x8039bc34 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
