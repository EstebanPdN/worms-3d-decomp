/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_audio_bars_802a6b30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D24lStringPCc = 0x8020bb54;
fn_802a64a8 = 0x802a64a8;
memset = 0x802eefe0;
w3d_a_80171fa0 = 0x80171fa0;
w3d_acquire_80171ee0 = 0x80171ee0;
w3d_as_mesh_8034357c = 0x8034357c;
w3d_b_80171ff8 = 0x80171ff8;
w3d_cast_mesh_80343808 = 0x80343808;
w3d_count_80171f90 = 0x80171f90;
w3d_handle_set_name_8015adf4 = 0x8015adf4;
w3d_runtime_service_lookup_8015ae3c = 0x8015ae3c;
w3d_s20_store_byte_value_80173f88 = 0x80173f88;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d24l_audio_bars_802a6b30 0x802a6b30 : { *(.text.d24l_audio_bars_802a6b30) }
  .rodata 0x803d6120 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
