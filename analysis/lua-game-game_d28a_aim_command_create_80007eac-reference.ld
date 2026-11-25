/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_aim_command_create_80007eac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_vt.10AimCommand = 0x8040dca8;
g_zero_8045e788 = 0x8045e788;
memcpy = 0x802eee50;
w3d_auto_8001523c = 0x8001523c;
w3d_cx9a_storage_push_member_8002274c = 0x8002274c;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_d28a_aim_command_create_80007eac 0x80007eac : { *(.text.w3d_d28a_aim_command_create_80007eac) }
  .rodata 0x8036956c : { *(.rodata) }
  .sdata 0x804aa564 (NOLOAD) : {
    . = 0x0; g_commands_804aa564 = .;
    . = 0x40; g_owner_804aa5a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
