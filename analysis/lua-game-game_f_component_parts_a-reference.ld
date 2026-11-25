/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_component_construct_800636e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_destroy = 0x80161050;
w3d_base_construct_8003dde0 = 0x8003dde0;
w3d_base_construct_8015fef0 = 0x8015fef0;
w3d_base_construct_801628b0 = 0x801628b0;
w3d_base_destroy_801628ec = 0x801628ec;
w3d_component_vtable_8040edc0 = 0x8040edc0;
w3d_component_vtable_8040ee00 = 0x8040ee00;
w3d_component_vtable_8040f120 = 0x8040f120;
w3d_component_vtable_8040f250 = 0x8040f250;
w3d_component_vtable_8040f2d0 = 0x8040f2d0;
w3d_component_vtable_8040f390 = 0x8040f390;
w3d_component_vtable_8040f6f8 = 0x8040f6f8;
w3d_f32_80379bf4 = 0x80379bf4;
w3d_f32_80379bf8 = 0x80379bf8;
w3d_f32_80379e14 = 0x80379e14;
w3d_f32_8037f740 = 0x8037f740;
w3d_f32_803820f4 = 0x803820f4;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_component_construct_800636e0 0x800636e0 : { *(.text.w3d_component_construct_800636e0) }
  .text.w3d_component_construct_80065070 0x80065070 : { *(.text.w3d_component_construct_80065070) }
  .text.w3d_component_destroy_80087a88 0x80087a88 : { *(.text.w3d_component_destroy_80087a88) }
  .text.w3d_component_construct_8009697c 0x8009697c : { *(.text.w3d_component_construct_8009697c) }
  .text.w3d_component_destroy_800969ec 0x800969ec : { *(.text.w3d_component_destroy_800969ec) }
  .text.w3d_component_construct_800980ac 0x800980ac : { *(.text.w3d_component_construct_800980ac) }
  .text.w3d_component_destroy_8009b4e0 0x8009b4e0 : { *(.text.w3d_component_destroy_8009b4e0) }
  .text.w3d_component_construct_800ada58 0x800ada58 : { *(.text.w3d_component_construct_800ada58) }
  .sdata 0x804aab4c (NOLOAD) : {
    . = 0x0; w3d_component_instance_804aab4c = .;
    . = 0x58; w3d_component_instance_804aaba4 = .;
    . = 0x9c; w3d_component_instance_804aabe8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
