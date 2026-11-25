/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8020430c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801299B8 = 0x801299b8;
fn_801FD238 = 0x801fd238;
fn_801FE45C = 0x801fe45c;
fn_80203370 = 0x80203370;
fn_80204760 = 0x80204760;
fn_802047E0 = 0x802047e0;
fn_80207B30 = 0x80207b30;
fn_802EF9C0 = 0x802ef9c0;
fn_8035BBF0 = 0x8035bbf0;
fn_8035BC90 = 0x8035bc90;
fn_8035BD50 = 0x8035bd50;
SECTIONS {
  .text.w3d_auto_8020430c 0x8020430c : { *(.text.w3d_auto_8020430c) }
  .text.w3d_auto_80204428 0x80204428 : { *(.text.w3d_auto_80204428) }
  .text.w3d_auto_80204448 0x80204448 : { *(.text.w3d_auto_80204448) }
  .text.w3d_auto_80204468 0x80204468 : { *(.text.w3d_auto_80204468) }
  .text.w3d_auto_80204488 0x80204488 : { *(.text.w3d_auto_80204488) }
  .text.w3d_auto_802044a8 0x802044a8 : { *(.text.w3d_auto_802044a8) }
  .text.w3d_auto_802044c8 0x802044c8 : { *(.text.w3d_auto_802044c8) }
  .text.w3d_auto_80204530 0x80204530 : { *(.text.w3d_auto_80204530) }
  .text.w3d_auto_80204720 0x80204720 : { *(.text.w3d_auto_80204720) }
  .text.w3d_auto_80204740 0x80204740 : { *(.text.w3d_auto_80204740) }
  .text.w3d_auto_80205648 0x80205648 : { *(.text.w3d_auto_80205648) }
  .text.w3d_auto_80205964 0x80205964 : { *(.text.w3d_auto_80205964) }
  .text.w3d_auto_8020596c 0x8020596c : { *(.text.w3d_auto_8020596c) }
  .text.w3d_auto_802062f4 0x802062f4 : { *(.text.w3d_auto_802062f4) }
  .text.w3d_auto_802068fc 0x802068fc : { *(.text.w3d_auto_802068fc) }
  .text.w3d_auto_802069e0 0x802069e0 : { *(.text.w3d_auto_802069e0) }
  .text.w3d_auto_80206a00 0x80206a00 : { *(.text.w3d_auto_80206a00) }
  .text.w3d_auto_80206b94 0x80206b94 : { *(.text.w3d_auto_80206b94) }
  .text.w3d_auto_80206ba0 0x80206ba0 : { *(.text.w3d_auto_80206ba0) }
  .text.w3d_auto_80206bac 0x80206bac : { *(.text.w3d_auto_80206bac) }
  .text.w3d_auto_80206bb8 0x80206bb8 : { *(.text.w3d_auto_80206bb8) }
  .text.w3d_auto_80206e0c 0x80206e0c : { *(.text.w3d_auto_80206e0c) }
  .text.w3d_auto_80206e14 0x80206e14 : { *(.text.w3d_auto_80206e14) }
  .text.w3d_auto_802071cc 0x802071cc : { *(.text.w3d_auto_802071cc) }
  .text.w3d_auto_802076ac 0x802076ac : { *(.text.w3d_auto_802076ac) }
  .text.w3d_auto_80207ca4 0x80207ca4 : { *(.text.w3d_auto_80207ca4) }
  .text.w3d_auto_80207d60 0x80207d60 : { *(.text.w3d_auto_80207d60) }
  .text.w3d_auto_80207e1c 0x80207e1c : { *(.text.w3d_auto_80207e1c) }
  .sdata 0x804ab98c (NOLOAD) : {
    . = 0x0; lbl_804AB98C = .;
    . = 0xc; lbl_804AB998 = .;
    . = 0x20; lbl_804AB9AC = .;
    . = 0x28; lbl_804AB9B4 = .;
    . = 0x2c; lbl_804AB9B8 = .;
    . = 0x4ccc; lbl_804B0658 = .;
    . = 0x4cce; lbl_804B065A = .;
    . = 0x4cd0; lbl_804B065C = .;
    . = 0x4cd2; lbl_804B065E = .;
    . = 0x5f68; lbl_804B18F4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
