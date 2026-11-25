/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26h_lunar_sky_setup_800a4534)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
float_assign_800fc4c8 = 0x800fc4c8;
g_8040fb28 = 0x8040fb28;
g_80410680 = 0x80410680;
property_read_800fc550 = 0x800fc550;
service_forward_8020b680 = 0x8020b680;
submit_80164514 = 0x80164514;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_format_8020c510 = 0x8020c510;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d26h_lunar_sky_setup_800a4534 0x800a4534 : { *(.text.d26h_lunar_sky_setup_800a4534) }
  .rodata 0x80380dec : { *(.rodata) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; g_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
