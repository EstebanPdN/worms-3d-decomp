/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41z_vfprintf_r_802f07a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__udivdi3 = 0x802f4460;
__umoddi3 = 0x802f4944;
bad_base_text_803dbd08 = 0x803dbd08;
blanks = 0x803dbcb8;
localeconv = 0x802f3204;
memchr = 0x802eed00;
memcpy = 0x802eee50;
null_text_803dbcec = 0x803dbcec;
strlen = 0x802ef9c0;
w3d_cx9c_multibyte_decode_802edb28 = 0x802edb28;
w3d_d40z_cvt_802f0118 = 0x802f0118;
w3d_d40z_log10_802e6564 = 0x802e6564;
w3d_vfprintf_console_write_802f05f0 = 0x802f05f0;
xdigits_lower_803dbcd8 = 0x803dbcd8;
xdigits_upper_803dbcf4 = 0x803dbcf4;
zeroes = 0x803dbcc8;
SECTIONS {
  .text.w3d_d41z_vfprintf_r_802f07a0 0x802f07a0 : { *(.text.w3d_d41z_vfprintf_r_802f07a0) }
  .rodata 0x803dbd28 : { *(.rodata) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; w3d_sda_impure_ptr_804ac570 = .;
    . = 0x28; w3d_sda_mb_cur_max_804ac598 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
