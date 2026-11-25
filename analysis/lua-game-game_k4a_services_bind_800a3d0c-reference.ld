/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_services_bind_800a3d0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80164514 = 0x80164514;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_service_8040de78 = 0x8040de78;
w3d_service_8040e1f8 = 0x8040e1f8;
w3d_service_8040e4e8 = 0x8040e4e8;
w3d_service_8040e928 = 0x8040e928;
w3d_service_8040edf0 = 0x8040edf0;
w3d_service_8040f458 = 0x8040f458;
w3d_service_8040f498 = 0x8040f498;
w3d_service_804102d8 = 0x804102d8;
w3d_service_804105a8 = 0x804105a8;
w3d_service_80410e30 = 0x80410e30;
SECTIONS {
  .text.k4a_services_bind_800a3d0c 0x800a3d0c : { *(.text.k4a_services_bind_800a3d0c) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_context_804b1788 = .;
    . = 0x4; w3d_context_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
