/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx13b_movie_update_802e0c8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
advance_802e1710 = 0x802e1710;
decode_802e1854 = 0x802e1854;
file_803db1f8 = 0x803db1f8;
frame_802e1b08 = 0x802e1b08;
instance_80343994 = 0x80343994;
message_803db294 = 0x803db294;
notify_801fdbec = 0x801fdbec;
poll_802f76e0 = 0x802f76e0;
report_802fb82c = 0x802fb82c;
ticks_80304c00 = 0x80304c00;
SECTIONS {
  .text.w3d_cx13b_movie_update_802e0c8c 0x802e0c8c : { *(.text.w3d_cx13b_movie_update_802e0c8c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
