/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_null_instance_not_implemented)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_instance_finish_8017b348 = 0x8017b348;
SECTIONS {
  .text.w3d_null_instance_not_implemented 0x801831d4 : { *(.text.w3d_null_instance_not_implemented) }
  .text.w3d_null_instance_owner_flags 0x801831e0 : { *(.text.w3d_null_instance_owner_flags) }
  .text.w3d_null_instance_shutdown 0x80183214 : { *(.text.w3d_null_instance_shutdown) }
  .text.w3d_null_instance_unbind 0x80183298 : { *(.text.w3d_null_instance_unbind) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; w3d_scene_list_804ab5fc = .;
    . = 0x54; w3d_null_active_count_804ab650 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
