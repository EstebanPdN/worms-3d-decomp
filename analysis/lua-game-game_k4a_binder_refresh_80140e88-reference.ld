/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_binder_refresh_80140e88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80164514 = 0x80164514;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80341584 = 0x80341584;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_service_80410a10 = 0x80410a10;
w3d_str_803a0430 = 0x803a0430;
SECTIONS {
  .text.k4a_binder_refresh_80140e88 0x80140e88 : { *(.text.k4a_binder_refresh_80140e88) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; w3d_context_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
