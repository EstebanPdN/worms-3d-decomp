/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80052154)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_f32_803782e4 = 0x803782e4;
w3d_fn_80035714 = 0x80035714;
w3d_fn_800d308c = 0x800d308c;
w3d_fn_800d5028 = 0x800d5028;
w3d_fn_8015f65c = 0x8015f65c;
w3d_fn_801613f0 = 0x801613f0;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_str_80378268 = 0x80378268;
w3d_str_80378270 = 0x80378270;
w3d_str_8037827c = 0x8037827c;
w3d_str_80378288 = 0x80378288;
w3d_str_80378298 = 0x80378298;
w3d_str_803782b0 = 0x803782b0;
w3d_str_803782c0 = 0x803782c0;
w3d_str_803782cc = 0x803782cc;
w3d_str_803782d4 = 0x803782d4;
w3d_str_803782dc = 0x803782dc;
SECTIONS {
  .text.w3d_fn_80052154 0x80052154 : { *(.text.w3d_fn_80052154) }
  .text.w3d_fn_80052360 0x80052360 : { *(.text.w3d_fn_80052360) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; w3d_view_804aa8c8 = .;
    . = 0xb58; w3d_flag_804ab420 = .;
    . = 0x2be8; w3d_message_804ad4b0 = .;
    . = 0x2bf0; w3d_message_804ad4b8 = .;
    . = 0x2bf8; w3d_message_804ad4c0 = .;
    . = 0x2c00; w3d_message_804ad4c8 = .;
    . = 0x6e8c; w3d_queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
