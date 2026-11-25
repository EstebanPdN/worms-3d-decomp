/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_spectator_message_801081dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015fb34 = 0x8015fb34;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_ctor_8015fef0 = 0x8015fef0;
w3d_ctor_801628b0 = 0x801628b0;
w3d_fn_800a8348 = 0x800a8348;
w3d_fn_801084b4 = 0x801084b4;
w3d_obj_80410700 = 0x80410700;
w3d_obj_80410738 = 0x80410738;
w3d_obj_80410778 = 0x80410778;
w3d_str_80399b90 = 0x80399b90;
SECTIONS {
  .text.w3d_spectator_message_801081dc 0x801081dc : { *(.text.w3d_spectator_message_801081dc) }
  .text.w3d_logo_construct_80108368 0x80108368 : { *(.text.w3d_logo_construct_80108368) }
  .text.w3d_logo_destroy_801083ac 0x801083ac : { *(.text.w3d_logo_destroy_801083ac) }
  .text.w3d_logo_dispatch_8010840c 0x8010840c : { *(.text.w3d_logo_dispatch_8010840c) }
  .text.w3d_service_construct_8010912c 0x8010912c : { *(.text.w3d_service_construct_8010912c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
