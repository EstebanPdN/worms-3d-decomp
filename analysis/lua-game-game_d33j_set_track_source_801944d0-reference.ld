/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(attach__12D33jPlaybackP10D33jSource)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_M_fill_insert__Q24_STLt6vector2Z7D33jKeyZt15ModuleAllocator1Z7D33jKeyP7D33jKeyUiRC7D33jKey = 0x8034f47c;
_M_fill_insert__Q24_STLt6vector2Z9D33jTrackZt15ModuleAllocator1Z9D33jTrackP9D33jTrackUiRC9D33jTrack = 0x8034f9e8;
__builtin_vec_delete = 0x801fe240;
__builtin_vec_new = 0x801fe220;
memset = 0x802eefe0;
w3d_auto_801907a8 = 0x801907a8;
w3d_auto_801907d0 = 0x801907d0;
SECTIONS {
  .text.attach__12D33jPlaybackP10D33jSource 0x801944d0 : { *(.text.attach__12D33jPlaybackP10D33jSource) }
  .rodata 0x803a82b8 : { *(.rodata) }
  .sdata 0x804ab6e8 (NOLOAD) : {
    . = 0x0; track_bytes_804ab6e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
