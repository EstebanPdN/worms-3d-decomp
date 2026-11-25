/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__sfp)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__sinit = 0x802eb1d4;
__sseek = 0x802ec4f8;
_fstat_r = 0x802f3278;
w3d_extra_files_8047d7d0 = 0x8047d7d0;
w3d_extra_glue_8047db90 = 0x8047db90;
SECTIONS {
  .text.__sfp 0x802eb284 : { *(.text.__sfp) }
  .text.__smakebuf 0x802ebee4 : { *(.text.__smakebuf) }
  .sdata 0x804ac578 (NOLOAD) : {
    . = 0x0; w3d_sda_stream_buffers_804ac578 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
