/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_libm_forward_802e83cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_findenv_r = 0x802eda34;
w3d_libm_body_802e9850 = 0x802e9850;
w3d_stream_flush_802eb084 = 0x802eb084;
w3d_stream_walk_802ebe64 = 0x802ebe64;
w3d_vfiprintf_r_802f1cf4 = 0x802f1cf4;
SECTIONS {
  .text.w3d_libm_forward_802e83cc 0x802e83cc : { *(.text.w3d_libm_forward_802e83cc) }
  .text.w3d_stream_walk_all_802eb4e4 0x802eb4e4 : { *(.text.w3d_stream_walk_all_802eb4e4) }
  .text.w3d_copy_bytes_802eb5f8 0x802eb5f8 : { *(.text.w3d_copy_bytes_802eb5f8) }
  .text.w3d_stream_flush_forward_802ec068 0x802ec068 : { *(.text.w3d_stream_flush_forward_802ec068) }
  .text.w3d_stdio_zero_802ec32c 0x802ec32c : { *(.text.w3d_stdio_zero_802ec32c) }
  .text.getenv 0x802eda04 : { *(.text.getenv) }
  .text.w3d_stdio_zero_802efe6c 0x802efe6c : { *(.text.w3d_stdio_zero_802efe6c) }
  .text.vfiprintf 0x802f1cb8 : { *(.text.vfiprintf) }
  .text.__env_lock 0x802f3564 : { *(.text.__env_lock) }
  .text.__env_unlock 0x802f3568 : { *(.text.__env_unlock) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; w3d_sda_impure_ptr_804ac570 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
