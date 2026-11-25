/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_r23a_service_shutdown_80029298)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
descriptor_80360b70 = 0x80360b70;
descriptor_80360ba0 = 0x80360ba0;
dispatch_8040e248 = 0x8040e248;
member_query_8012629c = 0x8012629c;
mode_update_8003ed10 = 0x8003ed10;
payload_operation_800d5028 = 0x800d5028;
payload_pending_clear_800ccd54 = 0x800ccd54;
payload_prepare_800d308c = 0x800d308c;
service_destroy_801628ec = 0x801628ec;
SECTIONS {
  .text.w3d_r23a_service_shutdown_80029298 0x80029298 : { *(.text.w3d_r23a_service_shutdown_80029298) }
  .text.w3d_r23a_set_scalar_query_8003e25c 0x8003e25c : { *(.text.w3d_r23a_set_scalar_query_8003e25c) }
  .text.w3d_r23a_update_mode_one_8003e370 0x8003e370 : { *(.text.w3d_r23a_update_mode_one_8003e370) }
  .text.w3d_r23a_payload_prepare_forward_800cc728 0x800cc728 : { *(.text.w3d_r23a_payload_prepare_forward_800cc728) }
  .text.w3d_r23a_payload_forward_800cc75c 0x800cc75c : { *(.text.w3d_r23a_payload_forward_800cc75c) }
  .text.w3d_r23a_descriptor_800cc77c 0x800cc77c : { *(.text.w3d_r23a_descriptor_800cc77c) }
  .text.w3d_r23a_retain_previous_800cc888 0x800cc888 : { *(.text.w3d_r23a_retain_previous_800cc888) }
  .text.w3d_r23a_invalid_result_800ccaf0 0x800ccaf0 : { *(.text.w3d_r23a_invalid_result_800ccaf0) }
  .text.w3d_r23a_payload_clear_800ccbf4 0x800ccbf4 : { *(.text.w3d_r23a_payload_clear_800ccbf4) }
  .text.w3d_r23a_descriptor_800cdaa8 0x800cdaa8 : { *(.text.w3d_r23a_descriptor_800cdaa8) }
  .text.w3d_r23a_retain_previous_800cdbb4 0x800cdbb4 : { *(.text.w3d_r23a_retain_previous_800cdbb4) }
  .sdata 0x804aa828 (NOLOAD) : {
    . = 0x0; active_service_804aa828 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
