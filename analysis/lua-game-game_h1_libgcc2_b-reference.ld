/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__fixdfdi)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__cmpdi2 = 0x802f36b4;
memset = 0x802eefe0;
w3d_eh_initialized_8047dd30 = 0x8047dd30;
w3d_eh_static_8047dd20 = 0x8047dd20;
w3d_eh_top_elt_8047dd34 = 0x8047dd34;
w3d_float_zero_803e7010 = 0x803e7010;
w3d_get_eh_context_80404b74 = 0x80404b74;
w3d_terminate_func_80404b70 = 0x80404b70;
SECTIONS {
  .text.__fixdfdi 0x802f3c74 : { *(.text.__fixdfdi) }
  .text.__fixunsdfdi 0x802f3cb8 : { *(.text.__fixunsdfdi) }
  .text.__floatdidf 0x802f3e70 : { *(.text.__floatdidf) }
  .text.__lshrdi3 0x802f3ecc : { *(.text.__lshrdi3) }
  .text.w3d_terminate_forward_802f4440 0x802f4440 : { *(.text.w3d_terminate_forward_802f4440) }
  .text.__terminate 0x802f4dec : { *(.text.__terminate) }
  .text.w3d_eh_context_initialize_802f4e18 0x802f4e18 : { *(.text.w3d_eh_context_initialize_802f4e18) }
  .text.w3d_eh_context_static_802f4e4c 0x802f4e4c : { *(.text.w3d_eh_context_static_802f4e4c) }
  .rodata 0x803e7030 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
