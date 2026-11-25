/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_name_registry_destroy_80069e94)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_name_list_destroy_800c45b8 = 0x800c45b8;
w3d_service_destroy_801628ec = 0x801628ec;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_vtable_8040ef98 = 0x8040ef98;
SECTIONS {
  .text.w3d_k10a_name_registry_destroy_80069e94 0x80069e94 : { *(.text.w3d_k10a_name_registry_destroy_80069e94) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; w3d_global_804aaabc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
