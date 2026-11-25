/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30e_voice_start_801e5b80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e59b4 = 0x801e59b4;
fn_802f51e4 = 0x802f51e4;
fn_802f5568 = 0x802f5568;
lbl_8045dbc8 = 0x8045dbc8;
w3d_aligned_allocate = 0x801fe2a8;
w3d_auto_801e64c0 = 0x801e64c0;
w3d_s21_is_playing_801e6c48 = 0x801e6c48;
w3d_stream_is_open = 0x801e4444;
SECTIONS {
  .text.w3d_d30e_voice_start_801e5b80 0x801e5b80 : { *(.text.w3d_d30e_voice_start_801e5b80) }
  .sdata 0x804ab85c (NOLOAD) : {
    . = 0x0; w3d_stream_system_804ab85c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
