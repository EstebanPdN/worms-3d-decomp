/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19b_update_eye_tracking_80097cbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
eye_main_clip_8037f660 = 0x8037f660;
minus_one_8037f70c = 0x8037f70c;
one_8037f708 = 0x8037f708;
w3d_eye_track_scale_80097e7c = 0x80097e7c;
w3d_mesh_fade_track_80181814 = 0x80181814;
w3d_mesh_instance_80343584 = 0x80343584;
w3d_mesh_instance_control_801817e0 = 0x801817e0;
w3d_transition_play_80181640 = 0x80181640;
w3d_transition_state_80181ccc = 0x80181ccc;
zero_8037f704 = 0x8037f704;
SECTIONS {
  .text.d19b_update_eye_tracking_80097cbc 0x80097cbc : { *(.text.d19b_update_eye_tracking_80097cbc) }
  .sdata 0x804aabac (NOLOAD) : {
    . = 0x0; eye_horizontal_track_804aabac = .;
    . = 0x4; eye_vertical_track_804aabb0 = .;
    . = 0x8; eye_reset_clip_804aabb4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
