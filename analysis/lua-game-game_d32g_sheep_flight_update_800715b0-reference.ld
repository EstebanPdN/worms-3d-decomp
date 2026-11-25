/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32g_sheep_flight_update_800715b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
w3d_auto_801797b4 = 0x801797b4;
w3d_d26e_euler_matrix_801a3eb0 = 0x801a3eb0;
w3d_empty_80341584 = 0x80341584;
w3d_engine_get_context = 0x80165254;
w3d_s21_multiply3_801f606c = 0x801f606c;
SECTIONS {
  .text.w3d_d32g_sheep_flight_update_800715b0 0x800715b0 : { *(.text.w3d_d32g_sheep_flight_update_800715b0) }
  .rodata 0x8037cab0 : { *(.rodata) }
  .sdata 0x804b1944 (NOLOAD) : {
    . = 0x0; step_804b1944 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
