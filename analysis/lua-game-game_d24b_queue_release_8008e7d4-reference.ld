/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_queue_release_8008e7d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_copy_802eee50 = 0x802eee50;
w3d_pending_80431e88 = 0x80431e88;
w3d_release_802134fc = 0x802134fc;
w3d_set_80251398 = 0x80251398;
w3d_team_owner_800b4d98 = 0x800b4d98;
w3d_teams_8043bb64 = 0x8043bb64;
SECTIONS {
  .text.w3d_d24b_queue_release_8008e7d4 0x8008e7d4 : { *(.text.w3d_d24b_queue_release_8008e7d4) }
  .sdata 0x804aab68 (NOLOAD) : {
    . = 0x0; w3d_active_804aab68 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
