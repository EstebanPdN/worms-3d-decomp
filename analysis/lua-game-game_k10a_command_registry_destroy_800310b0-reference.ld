/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_command_registry_destroy_800310b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_handle_member_destroy = 0x80126230;
w3d_cx9c_release_owner_80343df8 = 0x80343df8;
w3d_handle_storage_release = 0x802134fc;
w3d_k8a_item_list_destroy_800363a0 = 0x800363a0;
w3d_service_destroy_801628ec = 0x801628ec;
w3d_service_mode_destroy = 0x8015a39c;
w3d_vtable_8040e588 = 0x8040e588;
SECTIONS {
  .text.w3d_k10a_command_registry_destroy_800310b0 0x800310b0 : { *(.text.w3d_k10a_command_registry_destroy_800310b0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
