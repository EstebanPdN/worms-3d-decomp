/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_h1_ninja_camera_construct_800cc6d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800d2dec = 0x800d2dec;
fn_800d308c = 0x800d308c;
fn_800d5028 = 0x800d5028;
s8_destroy_800cdd68 = 0x800cdd68;
w3d_auto_800d31d8 = 0x800d31d8;
w3d_global_80360b70 = 0x80360b70;
w3d_global_80360ba0 = 0x80360ba0;
w3d_global_8040fb90 = 0x8040fb90;
w3d_owner_list_remove = 0x8020fd2c;
w3d_payload_pending_clear_800ccd54 = 0x800ccd54;
w3d_payload_state_destroy_800cc908 = 0x800cc908;
w3d_registry_list_80360b70 = 0x80360b70;
w3d_registry_list_80360ba0 = 0x80360ba0;
w3d_string_ninja_80387d74 = 0x80387d74;
w3d_string_ninja_camera_80387d7c = 0x80387d7c;
SECTIONS {
  .text.w3d_h1_ninja_camera_construct_800cc6d0 0x800cc6d0 : { *(.text.w3d_h1_ninja_camera_construct_800cc6d0) }
  .text.w3d_h1_ninja_camera_destroy_800cc728 0x800cc728 : { *(.text.w3d_h1_ninja_camera_destroy_800cc728) }
  .text.w3d_h1_forward_800cc75c 0x800cc75c : { *(.text.w3d_h1_forward_800cc75c) }
  .text.w3d_address_800cc77c 0x800cc77c : { *(.text.w3d_address_800cc77c) }
  .text.w3d_registry_unlink_800cc788 0x800cc788 : { *(.text.w3d_registry_unlink_800cc788) }
  .text.w3d_registry_release_800cc82c 0x800cc82c : { *(.text.w3d_registry_release_800cc82c) }
  .text.w3d_registry_retain_800cc888 0x800cc888 : { *(.text.w3d_registry_retain_800cc888) }
  .text.w3d_constant_800ccaf0 0x800ccaf0 : { *(.text.w3d_constant_800ccaf0) }
  .text.w3d_h1_forward_800ccbf4 0x800ccbf4 : { *(.text.w3d_h1_forward_800ccbf4) }
  .text.w3d_address_800cdaa8 0x800cdaa8 : { *(.text.w3d_address_800cdaa8) }
  .text.w3d_registry_unlink_800cdab4 0x800cdab4 : { *(.text.w3d_registry_unlink_800cdab4) }
  .text.w3d_registry_release_800cdb58 0x800cdb58 : { *(.text.w3d_registry_release_800cdb58) }
  .text.w3d_registry_retain_800cdbb4 0x800cdbb4 : { *(.text.w3d_registry_retain_800cdbb4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
