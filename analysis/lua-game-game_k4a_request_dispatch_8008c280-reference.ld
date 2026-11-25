/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_request_dispatch_8008c280)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80164514 = 0x80164514;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_service_8040e708 = 0x8040e708;
SECTIONS {
  .text.k4a_request_dispatch_8008c280 0x8008c280 : { *(.text.k4a_request_dispatch_8008c280) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; w3d_context_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
