/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_h1_worm_script_speech_apply_8013e6f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8013bd0c = 0x8013bd0c;
s8_index_query_800fc7f8 = 0x800fc7f8;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_string_current_team_index_803b4f6c = 0x803b4f6c;
w3d_string_worm_script_speech_8039fca0 = 0x8039fca0;
SECTIONS {
  .text.w3d_h1_worm_script_speech_apply_8013e6f0 0x8013e6f0 : { *(.text.w3d_h1_worm_script_speech_apply_8013e6f0) }
  .text.w3d_h1_current_team_value_8021eb00 0x8021eb00 : { *(.text.w3d_h1_current_team_value_8021eb00) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
