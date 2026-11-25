/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_set_color_from_message_801697b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178f54 = 0x80178f54;
fn_801e25d4 = 0x801e25d4;
fn_801e4120 = 0x801e4120;
fn_801e41d0 = 0x801e41d0;
fn_8026b2c4 = 0x8026b2c4;
fn_802b1258 = 0x802b1258;
fn_802b16c4 = 0x802b16c4;
lbl_803a5058 = 0x803a5058;
lbl_803b0800 = 0x803b0800;
SECTIONS {
  .text.w3d_set_color_from_message_801697b4 0x801697b4 : { *(.text.w3d_set_color_from_message_801697b4) }
  .text.w3d_open_stream_801e6b1c 0x801e6b1c : { *(.text.w3d_open_stream_801e6b1c) }
  .text.w3d_set_render_mode_8026b334 0x8026b334 : { *(.text.w3d_set_render_mode_8026b334) }
  .sdata 0x804ab80c (NOLOAD) : {
    . = 0x0; lbl_804ab80c = .;
    . = 0x50; lbl_804ab85c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
