/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(fread)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__sinit = 0x802eb1d4;
__smakebuf = 0x802ebee4;
_fwalk = 0x802ebe64;
fflush = 0x802eb084;
strlen = 0x802ef9c0;
w3d_auto_802e3294 = 0x802e3294;
w3d_copy_bytes_802eb5f8 = 0x802eb5f8;
w3d_stdio_zero_802ec32c = 0x802ec32c;
w3d_stream_flush_forward_802ec068 = 0x802ec068;
w3d_svfscanf_802ec708 = 0x802ec708;
w3d_ungetc_overflow_text_803db57c = 0x803db57c;
SECTIONS {
  .text.fread 0x802eb624 : { *(.text.fread) }
  .text.__srefill 0x802ec088 : { *(.text.__srefill) }
  .text.sscanf 0x802ec334 : { *(.text.sscanf) }
  .text.ungetc 0x802ec584 : { *(.text.ungetc) }
  .text.__swsetup 0x802ed6b0 : { *(.text.__swsetup) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; w3d_sda_impure_ptr_804ac570 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
