/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40z_vfiprintf_r_802f1cf4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__udivdi3 = 0x802f4460;
__umoddi3 = 0x802f4944;
bad_base_text_803dbd98 = 0x803dbd98;
blanks_803dbd48 = 0x803dbd48;
memchr = 0x802eed00;
memcpy = 0x802eee50;
null_text_803dbd7c = 0x803dbd7c;
strlen = 0x802ef9c0;
w3d_cx9c_multibyte_decode_802edb28 = 0x802edb28;
w3d_vfiprintf_console_write_802f1be0 = 0x802f1be0;
xdigits_lower_803dbd68 = 0x803dbd68;
xdigits_upper_803dbd84 = 0x803dbd84;
zeroes_803dbd58 = 0x803dbd58;
SECTIONS {
  .text.w3d_d40z_vfiprintf_r_802f1cf4 0x802f1cf4 : { *(.text.w3d_d40z_vfiprintf_r_802f1cf4) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; w3d_sda_impure_ptr_804ac570 = .;
    . = 0x28; w3d_sda_mb_cur_max_804ac598 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
