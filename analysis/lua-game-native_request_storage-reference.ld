/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_request_service_shutdown)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_buffer_request_service = 0x80343944;
w3d_request_backend_base = 0x80311d08;
w3d_request_backend_initialize = 0x80313754;
w3d_request_backend_size = 0x80311d10;
w3d_request_capacity_failure = 0x803b33f8;
w3d_request_maintenance_a = 0x801ea57c;
w3d_request_maintenance_b = 0x80209b78;
w3d_request_report_failure = 0x801fcb64;
w3d_request_service_storage = 0x8042d780;
w3d_request_storage_coalesce = 0x8020f778;
w3d_request_storage_release = 0x8020f660;
SECTIONS {
  .text.w3d_request_service_shutdown 0x80069a64 : { *(.text.w3d_request_service_shutdown) }
  .text.w3d_request_storage_maintenance 0x8006e6c8 : { *(.text.w3d_request_storage_maintenance) }
  .text.w3d_request_destroy 0x8020f35c : { *(.text.w3d_request_destroy) }
  .text.w3d_request_storage_finalize 0x8020f468 : { *(.text.w3d_request_storage_finalize) }
  .text.w3d_request_storage_reset 0x8020f82c : { *(.text.w3d_request_storage_reset) }
  .text.w3d_request_storage_append_block 0x8020f850 : { *(.text.w3d_request_storage_append_block) }
  .text.w3d_request_storage_backing_initialize 0x8020f8d4 : { *(.text.w3d_request_storage_backing_initialize) }
  .text.w3d_request_storage_finish 0x8020f938 : { *(.text.w3d_request_storage_finish) }
  .text.w3d_request_service_destroy 0x80341398 : { *(.text.w3d_request_service_destroy) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
