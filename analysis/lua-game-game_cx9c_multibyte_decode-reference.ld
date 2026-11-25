/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9c_multibyte_decode_802edb28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx9c_euc_name_803db618 = 0x803db618;
cx9c_jis_actions_80404934 = 0x80404934;
cx9c_jis_name_803db620 = 0x803db620;
cx9c_jis_states_80404784 = 0x80404784;
cx9c_sjis_name_803db610 = 0x803db610;
cx9c_strcmp_802ef234 = 0x802ef234;
cx9c_strlen_802ef9c0 = 0x802ef9c0;
SECTIONS {
  .text.w3d_cx9c_multibyte_decode_802edb28 0x802edb28 : { *(.text.w3d_cx9c_multibyte_decode_802edb28) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
