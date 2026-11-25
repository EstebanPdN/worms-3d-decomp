/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_owner_bind_service_800beac8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_s20_forward_owner_801750f4 = 0x801750f4;
w3d_service_804144f8 = 0x804144f8;
SECTIONS {
  .text.k4a_owner_bind_service_800beac8 0x800beac8 : { *(.text.k4a_owner_bind_service_800beac8) }
  .sdata 0x804ae5e4 (NOLOAD) : {
    . = 0x0; w3d_held_804ae5e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
