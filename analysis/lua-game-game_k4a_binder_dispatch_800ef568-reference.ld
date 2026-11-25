/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_binder_dispatch_800ef568)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80164514 = 0x80164514;
w3d_assign_interface_arg_8002f6dc = 0x8002f6dc;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_service_8040e4a8 = 0x8040e4a8;
SECTIONS {
  .text.k4a_binder_dispatch_800ef568 0x800ef568 : { *(.text.k4a_binder_dispatch_800ef568) }
  .sdata 0x804aab4c (NOLOAD) : {
    . = 0x0; w3d_settings_804aab4c = .;
    . = 0x6c40; w3d_context_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
