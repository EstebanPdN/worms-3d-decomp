/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40z_cvt_802f0118)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cvt_buffer_8047db9c = 0x8047db9c;
itoa = 0x802f009c;
text_ind_803dbc80 = 0x803dbc80;
text_inf_803dbc70 = 0x803dbc70;
text_nan_803dbc7c = 0x803dbc7c;
text_neg_inf_803dbc74 = 0x803dbc74;
w3d_d24z_floor_802e75d0 = 0x802e75d0;
w3d_d40z_fmod_802e5f48 = 0x802e5f48;
w3d_round_up_digits_802efff4 = 0x802efff4;
SECTIONS {
  .text.w3d_d40z_cvt_802f0118 0x802f0118 : { *(.text.w3d_d40z_cvt_802f0118) }
  .rodata 0x803dbc88 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
