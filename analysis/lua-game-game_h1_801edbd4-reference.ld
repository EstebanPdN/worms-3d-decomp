/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_h1_release_task_arrays_801edbd4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_task_array_release_backend = 0x801fe288;
SECTIONS {
  .text.w3d_h1_release_task_arrays_801edbd4 0x801edbd4 : { *(.text.w3d_h1_release_task_arrays_801edbd4) }
  .text.w3d_h1_service_shutdown_802cafd0 0x802cafd0 : { *(.text.w3d_h1_service_shutdown_802cafd0) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; w3d_sda_service_state_804abce4 = .;
    . = 0x48c4; w3d_sda_task_array_804b05a8 = .;
    . = 0x48c8; w3d_sda_task_array_804b05ac = .;
    . = 0x48cc; w3d_sda_task_array_804b05b0 = .;
    . = 0x48d0; w3d_sda_task_array_804b05b4 = .;
    . = 0x53cc; w3d_sda_service_804b10b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
