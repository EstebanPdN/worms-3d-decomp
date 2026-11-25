/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_r23a_service_shutdown_80029298)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
dispatch_8040e248 = 0x8040e248;
member_query_8012629c = 0x8012629c;
service_destroy_801628ec = 0x801628ec;
SECTIONS {
  .text.w3d_r23a_service_shutdown_80029298 0x80029298 : { *(.text.w3d_r23a_service_shutdown_80029298) }
  .text.w3d_r23a_set_scalar_query_8003e25c 0x8003e25c : { *(.text.w3d_r23a_set_scalar_query_8003e25c) }
  .sdata 0x804aa828 (NOLOAD) : {
    . = 0x0; active_service_804aa828 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
