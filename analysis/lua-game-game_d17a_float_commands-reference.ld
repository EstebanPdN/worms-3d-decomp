/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d17a_command_create_800085fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20D17aCommand_80021514 = 0x80021514;
__20D17aCommand_80021768 = 0x80021768;
d17a_allocate_8001523c = 0x8001523c;
d17a_allocate_80212fd4 = 0x80212fd4;
d17a_command_table_16_8040dbc8 = 0x8040dbc8;
d17a_copy_802eee50 = 0x802eee50;
d17a_register_8002274c = 0x8002274c;
d17a_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_d17a_command_create_800085fc 0x800085fc : { *(.text.w3d_d17a_command_create_800085fc) }
  .text.w3d_d17a_command_create_8000889c 0x8000889c : { *(.text.w3d_d17a_command_create_8000889c) }
  .text.w3d_d17a_command_create_16_80009014 0x80009014 : { *(.text.w3d_d17a_command_create_16_80009014) }
  .sdata 0x804aa564 (NOLOAD) : {
    . = 0x0; d17a_commands_804aa564 = .;
    . = 0x40; d17a_registry_804aa5a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
