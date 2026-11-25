/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_music_messages_80051df8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
base_8016293c = 0x8016293c;
id_equals_8015f65c = 0x8015f65c;
init_80051f94 = 0x80051f94;
msg_text_8010a8fc = 0x8010a8fc;
msg_vec_80126034 = 0x80126034;
shutdown_80052004 = 0x80052004;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d24g_music_messages_80051df8 0x80051df8 : { *(.text.w3d_d24g_music_messages_80051df8) }
  .sdata 0x804ad478 (NOLOAD) : {
    . = 0x0; c_804ad478 = .;
    . = 0x8; c_804ad480 = .;
    . = 0x4310; app_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
