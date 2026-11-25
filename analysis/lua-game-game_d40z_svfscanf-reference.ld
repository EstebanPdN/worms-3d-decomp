/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40z_svfscanf_802ec708)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__srefill = 0x802ec088;
atof = 0x802ed878;
basefix_803db5c0 = 0x803db5c0;
fread = 0x802eb624;
strtol = 0x802f3198;
strtoul = 0x802eecc8;
ungetc = 0x802ec584;
w3d_ctype_803db449 = 0x803db449;
w3d_cx7c_scan_character_set_802ed50c = 0x802ed50c;
w3d_cx9c_multibyte_decode_802edb28 = 0x802edb28;
SECTIONS {
  .text.w3d_d40z_svfscanf_802ec708 0x802ec708 : { *(.text.w3d_d40z_svfscanf_802ec708) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; w3d_sda_impure_ptr_804ac570 = .;
    . = 0x28; w3d_sda_mb_cur_max_804ac598 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
