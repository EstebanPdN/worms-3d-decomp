/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_method_command_append_80003558)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__12MethodMember = 0x801181bc;
__builtin_new = 0x801fe1d8;
memcpy = 0x802eee50;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_d28a_method_command_append_80003558 0x80003558 : { *(.text.w3d_d28a_method_command_append_80003558) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
