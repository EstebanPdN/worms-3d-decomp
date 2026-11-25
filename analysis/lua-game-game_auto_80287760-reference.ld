/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80287760)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015F5A0 = 0x8015f5a0;
fn_8015FD1C = 0x8015fd1c;
fn_80162024 = 0x80162024;
fn_80165254 = 0x80165254;
fn_80287D30 = 0x80287d30;
fn_8028A3FC = 0x8028a3fc;
fn_8028D34C = 0x8028d34c;
fn_8028D3B8 = 0x8028d3b8;
fn_802B0990 = 0x802b0990;
fn_802B0B84 = 0x802b0b84;
fn_802B0FEC = 0x802b0fec;
fn_802B15E0 = 0x802b15e0;
fn_802B1BD0 = 0x802b1bd0;
fn_802B1F98 = 0x802b1f98;
SECTIONS {
  .text.w3d_auto_80287760 0x80287760 : { *(.text.w3d_auto_80287760) }
  .text.w3d_auto_80287c38 0x80287c38 : { *(.text.w3d_auto_80287c38) }
  .text.w3d_auto_80289a08 0x80289a08 : { *(.text.w3d_auto_80289a08) }
  .text.w3d_auto_8028b7c0 0x8028b7c0 : { *(.text.w3d_auto_8028b7c0) }
  .text.w3d_auto_8028b7e4 0x8028b7e4 : { *(.text.w3d_auto_8028b7e4) }
  .text.w3d_auto_8028d1e4 0x8028d1e4 : { *(.text.w3d_auto_8028d1e4) }
  .text.w3d_auto_8028d274 0x8028d274 : { *(.text.w3d_auto_8028d274) }
  .text.w3d_auto_8028d2ac 0x8028d2ac : { *(.text.w3d_auto_8028d2ac) }
  .text.w3d_auto_8028d2d0 0x8028d2d0 : { *(.text.w3d_auto_8028d2d0) }
  .text.w3d_auto_8028d2f4 0x8028d2f4 : { *(.text.w3d_auto_8028d2f4) }
  .text.w3d_auto_8028d328 0x8028d328 : { *(.text.w3d_auto_8028d328) }
  .sdata 0x804b0bcc (NOLOAD) : {
    . = 0x0; lbl_804B0BCC = .;
    . = 0x20; lbl_804B0BEC = .;
    . = 0x28; lbl_804B0BF4 = .;
    . = 0x30; lbl_804B0BFC = .;
    . = 0x38; lbl_804B0C04 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
