/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d21a_audio_theme_8002988c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcmp = 0x802ef234;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_default_sfx_volume_80372374 = 0x80372374;
w3d_float_property_800fc270 = 0x800fc270;
w3d_random_80162c20 = 0x80162c20;
w3d_string_80372018 = 0x80372018;
w3d_string_80372020 = 0x80372020;
w3d_string_80372024 = 0x80372024;
w3d_string_80372030 = 0x80372030;
w3d_string_80372040 = 0x80372040;
w3d_string_80372048 = 0x80372048;
w3d_string_8037204c = 0x8037204c;
w3d_string_80372054 = 0x80372054;
w3d_string_8037205c = 0x8037205c;
w3d_string_80372080 = 0x80372080;
w3d_string_80372088 = 0x80372088;
w3d_string_80372090 = 0x80372090;
w3d_string_80372110 = 0x80372110;
w3d_string_8037211c = 0x8037211c;
w3d_string_80372128 = 0x80372128;
w3d_string_80372134 = 0x80372134;
w3d_string_80372140 = 0x80372140;
w3d_string_80372150 = 0x80372150;
w3d_string_80372178 = 0x80372178;
w3d_string_80372184 = 0x80372184;
w3d_string_80372190 = 0x80372190;
w3d_string_8037219c = 0x8037219c;
w3d_string_803721a8 = 0x803721a8;
w3d_string_803721b4 = 0x803721b4;
w3d_string_803721dc = 0x803721dc;
w3d_string_803721e8 = 0x803721e8;
w3d_string_803721f4 = 0x803721f4;
w3d_string_80372200 = 0x80372200;
w3d_string_8037220c = 0x8037220c;
w3d_string_8037221c = 0x8037221c;
w3d_string_80372244 = 0x80372244;
w3d_string_80372250 = 0x80372250;
w3d_string_8037225c = 0x8037225c;
w3d_string_80372268 = 0x80372268;
w3d_string_80372274 = 0x80372274;
w3d_string_80372284 = 0x80372284;
w3d_string_803722a8 = 0x803722a8;
w3d_string_803722b0 = 0x803722b0;
w3d_string_803722b8 = 0x803722b8;
w3d_string_803722c0 = 0x803722c0;
w3d_string_803722c8 = 0x803722c8;
w3d_string_803722d4 = 0x803722d4;
w3d_string_803722f0 = 0x803722f0;
w3d_string_803722fc = 0x803722fc;
w3d_string_80372308 = 0x80372308;
w3d_string_80372314 = 0x80372314;
w3d_string_80372320 = 0x80372320;
w3d_string_80372330 = 0x80372330;
w3d_string_80372340 = 0x80372340;
w3d_string_80372350 = 0x80372350;
w3d_string_80372364 = 0x80372364;
w3d_string_property_800fc2b0 = 0x800fc2b0;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.w3d_d21a_audio_theme_8002988c 0x8002988c : { *(.text.w3d_d21a_audio_theme_8002988c) }
  .sdata 0x804acbfc (NOLOAD) : {
    . = 0x0; w3d_message_804acbfc = .;
    . = 0x8; w3d_message_804acc04 = .;
    . = 0x10; w3d_message_804acc0c = .;
    . = 0x4b8c; w3d_services_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
