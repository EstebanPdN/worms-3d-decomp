/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9b_global_service_refresh_80200278)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
service_8020b648 = 0x8020b648;
service_name_80419500 = 0x80419500;
SECTIONS {
  .text.w3d_cx9b_global_service_refresh_80200278 0x80200278 : { *(.text.w3d_cx9b_global_service_refresh_80200278) }
  .sdata 0x804b063c (NOLOAD) : {
    . = 0x0; held_service_804b063c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
