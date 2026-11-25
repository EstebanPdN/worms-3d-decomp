/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_request_write_complete)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_register_shutdown = 0x802ed7e0;
w3d_request_cache_flush = 0x802fa988;
w3d_request_cache_invalidate = 0x802fa95c;
w3d_request_hardware_post = 0x803137c4;
w3d_request_interrupts_disable = 0x802fdb6c;
w3d_request_interrupts_restore = 0x802fdb94;
w3d_request_read_bad_callback = 0x803b3334;
w3d_request_read_timeout = 0x803b3478;
w3d_request_report_failure = 0x801fcb64;
w3d_request_service_shutdown = 0x80069a64;
w3d_request_service_storage = 0x8042d780;
w3d_request_write_bad_callback = 0x803b331c;
w3d_request_write_timeout = 0x803b3448;
SECTIONS {
  .text.w3d_request_write_complete 0x8020f2cc : { *(.text.w3d_request_write_complete) }
  .text.w3d_request_read_complete 0x8020f314 : { *(.text.w3d_request_read_complete) }
  .text.w3d_buffer_request_state 0x8020f3b0 : { *(.text.w3d_buffer_request_state) }
  .text.w3d_request_prepare_write 0x8020f3b8 : { *(.text.w3d_request_prepare_write) }
  .text.w3d_request_prepare_read 0x8020f3e8 : { *(.text.w3d_request_prepare_read) }
  .text.w3d_buffer_request_read 0x8020f618 : { *(.text.w3d_buffer_request_read) }
  .text.w3d_request_transfer_write 0x8020f940 : { *(.text.w3d_request_transfer_write) }
  .text.w3d_request_transfer_read 0x8020fa04 : { *(.text.w3d_request_transfer_read) }
  .text.w3d_buffer_request_service 0x80343944 : { *(.text.w3d_buffer_request_service) }
  .text.w3d_request_service_initialize 0x80343a28 : { *(.text.w3d_request_service_initialize) }
  .sdata 0x804aba44 (NOLOAD) : {
    . = 0x0; w3d_request_serial = .;
    . = 0x1c2c; w3d_request_service_guard = .;
    . = 0x4c6c; w3d_active_request = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
