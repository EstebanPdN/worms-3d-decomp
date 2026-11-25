/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc26a_grid_build_path_8001ebe0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc26a_append_80003424 = 0x80003424;
cc26a_next_800062bc = 0x800062bc;
cc26a_position_8000419c = 0x8000419c;
cc26a_probe_8001f1d8 = 0x8001f1d8;
cc26a_refresh_8001ef50 = 0x8001ef50;
cc26a_release_800062ec = 0x800062ec;
cc26a_remaining_800062b0 = 0x800062b0;
cc26a_start_80004498 = 0x80004498;
cc26a_status_80005e10 = 0x80005e10;
cc26a_step_800046c8 = 0x800046c8;
SECTIONS {
  .text.cc26a_grid_build_path_8001ebe0 0x8001ebe0 : { *(.text.cc26a_grid_build_path_8001ebe0) }
  .sdata 0x804aa6c0 (NOLOAD) : {
    . = 0x0; cc26a_actor_804aa6c0 = .;
    . = 0xd4; cc26a_special_804aa794 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
