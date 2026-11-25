/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30e_voice_update_801e6054)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e41d0 = 0x801e41d0;
fn_802fa988 = 0x802fa988;
lbl_8045dbc8 = 0x8045dbc8;
w3d_auto_801e5dfc = 0x801e5dfc;
w3d_d26e_voice_volume_801e68d4 = 0x801e68d4;
w3d_facing_term_801e663c = 0x801e663c;
w3d_facing_term_801e6788 = 0x801e6788;
w3d_open_stream_801e6b1c = 0x801e6b1c;
w3d_s21_is_busy_801e5fd4 = 0x801e5fd4;
w3d_s21_link_query_801e65fc = 0x801e65fc;
w3d_s21_register_stream_801e6cd0 = 0x801e6cd0;
w3d_s21_reset_801e6bbc = 0x801e6bbc;
w3d_sound_sample_get_44 = 0x801e25d4;
w3d_stream_is_open = 0x801e4444;
w3d_stream_open_mono = 0x801e4120;
w3d_stream_set_mix = 0x801e46f4;
SECTIONS {
  .text.w3d_d30e_voice_update_801e6054 0x801e6054 : { *(.text.w3d_d30e_voice_update_801e6054) }
  .rodata 0x803b07c4 : { *(.rodata) }
  .sdata 0x804ab80c (NOLOAD) : {
    . = 0x0; w3d_sound_config_804ab80c = .;
    . = 0x50; w3d_stream_system_804ab85c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
