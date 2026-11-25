/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_newlib_std_802eb178)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_802e3294 = 0x802e3294;
w3d_auto_802e32b4 = 0x802e32b4;
w3d_auto_802e32d4 = 0x802e32d4;
w3d_auto_802e32e4 = 0x802e32e4;
w3d_auto_802e3304 = 0x802e3304;
SECTIONS {
  .text.w3d_newlib_std_802eb178 0x802eb178 : { *(.text.w3d_newlib_std_802eb178) }
  .text._fwalk 0x802ebe64 : { *(.text._fwalk) }
  .text.__sread 0x802ec424 : { *(.text.__sread) }
  .text.__swrite 0x802ec488 : { *(.text.__swrite) }
  .text.__sseek 0x802ec4f8 : { *(.text.__sseek) }
  .text.__sclose 0x802ec55c : { *(.text.__sclose) }
  .text._close_r 0x802f3228 : { *(.text._close_r) }
  .text._fstat_r 0x802f3278 : { *(.text._fstat_r) }
  .text._lseek_r 0x802f32d0 : { *(.text._lseek_r) }
  .text._read_r 0x802f3384 : { *(.text._read_r) }
  .text._write_r 0x802f33dc : { *(.text._write_r) }
  .sdata 0x804b1910 (NOLOAD) : {
    . = 0x0; w3d_sda_errno_804b1910 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
