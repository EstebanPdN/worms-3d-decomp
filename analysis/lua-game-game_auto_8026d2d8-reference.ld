/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8026d2d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015F5A0 = 0x8015f5a0;
fn_8015FD1C = 0x8015fd1c;
fn_80162024 = 0x80162024;
fn_8026DBE8 = 0x8026dbe8;
fn_8027014C = 0x8027014c;
fn_80280370 = 0x80280370;
fn_802870FC = 0x802870fc;
fn_802B0668 = 0x802b0668;
fn_802B0FEC = 0x802b0fec;
fn_802B1BD0 = 0x802b1bd0;
fn_802B1F98 = 0x802b1f98;
fn_802B2344 = 0x802b2344;
fn_802CC58C = 0x802cc58c;
SECTIONS {
  .text.w3d_auto_8026d2d8 0x8026d2d8 : { *(.text.w3d_auto_8026d2d8) }
  .text.w3d_auto_8026eca8 0x8026eca8 : { *(.text.w3d_auto_8026eca8) }
  .text.w3d_auto_8026ecdc 0x8026ecdc : { *(.text.w3d_auto_8026ecdc) }
  .text.w3d_auto_802702c8 0x802702c8 : { *(.text.w3d_auto_802702c8) }
  .text.w3d_auto_80270bdc 0x80270bdc : { *(.text.w3d_auto_80270bdc) }
  .text.w3d_auto_80270c04 0x80270c04 : { *(.text.w3d_auto_80270c04) }
  .text.w3d_auto_80271118 0x80271118 : { *(.text.w3d_auto_80271118) }
  .text.w3d_auto_8027bd04 0x8027bd04 : { *(.text.w3d_auto_8027bd04) }
  .text.w3d_auto_8027be70 0x8027be70 : { *(.text.w3d_auto_8027be70) }
  .text.w3d_auto_80285b00 0x80285b00 : { *(.text.w3d_auto_80285b00) }
  .text.w3d_auto_80285cf8 0x80285cf8 : { *(.text.w3d_auto_80285cf8) }
  .text.w3d_auto_80285d2c 0x80285d2c : { *(.text.w3d_auto_80285d2c) }
  .text.w3d_auto_802870c4 0x802870c4 : { *(.text.w3d_auto_802870c4) }
  .sdata 0x804abbac (NOLOAD) : {
    . = 0x0; lbl_804ABBAC = .;
    . = 0x4f2c; lbl_804B0AD8 = .;
    . = 0x4f90; lbl_804B0B3C = .;
    . = 0x4f98; lbl_804B0B44 = .;
    . = 0x4fa0; lbl_804B0B4C = .;
    . = 0x4fa8; lbl_804B0B54 = .;
    . = 0x4fb0; lbl_804B0B5C = .;
    . = 0x4fb8; lbl_804B0B64 = .;
    . = 0x4fc0; lbl_804B0B6C = .;
    . = 0x4fc8; lbl_804B0B74 = .;
    . = 0x4fd0; lbl_804B0B7C = .;
    . = 0x4fd8; lbl_804B0B84 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
