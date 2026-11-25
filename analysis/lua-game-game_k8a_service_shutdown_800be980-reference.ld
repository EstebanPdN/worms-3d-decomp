/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_service_shutdown_800be980)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8002c490 = 0x8002c490;
w3d_tables_destroy_800bb3a0 = 0x800bb3a0;
SECTIONS {
  .text.w3d_k8a_service_shutdown_800be980 0x800be980 : { *(.text.w3d_k8a_service_shutdown_800be980) }
  .sdata 0x804ae5d8 (NOLOAD) : {
    . = 0x0; w3d_held_804ae5d8 = .;
    . = 0x4; w3d_held_804ae5dc = .;
    . = 0x8; w3d_held_804ae5e0 = .;
    . = 0xc; w3d_held_804ae5e4 = .;
    . = 0x3208; w3d_flag_804b17e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
