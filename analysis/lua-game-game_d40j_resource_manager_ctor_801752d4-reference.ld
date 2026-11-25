/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__19D40jResourceManager)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__builtin_vec_new = 0x801fe220;
bucket_init_8034cb20 = 0x8034cb20;
hook_init_801788e4 = 0x801788e4;
malloc = 0x80212fd4;
memcpy_802eee50 = 0x802eee50;
memmove_802eeef4 = 0x802eeef4;
name_max_hooks_803a6844 = 0x803a6844;
name_max_instances_803a6830 = 0x803a6830;
settings_int_80206920 = 0x80206920;
vt_80412250 = 0x80412250;
vt_80412318 = 0x80412318;
vt_804123e0 = 0x804123e0;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.__19D40jResourceManager 0x801752d4 : { *(.text.__19D40jResourceManager) }
  .sdata 0x804ab5ac (NOLOAD) : {
    . = 0x0; lbl_804ab5ac = .;
    . = 0x4; lbl_804ab5b0 = .;
    . = 0x8; lbl_804ab5b4 = .;
    . = 0xc; lbl_804ab5b8 = .;
    . = 0x10; lbl_804ab5bc = .;
    . = 0x14; lbl_804ab5c0 = .;
    . = 0x18; lbl_804ab5c4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
