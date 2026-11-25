/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8028dbf8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800C4604 = 0x800c4604;
fn_800C4660 = 0x800c4660;
fn_8015CCBC = 0x8015ccbc;
fn_8015F5A0 = 0x8015f5a0;
fn_80162024 = 0x80162024;
fn_8028D34C = 0x8028d34c;
fn_8028E9C0 = 0x8028e9c0;
fn_802B2344 = 0x802b2344;
fn_8035EE24 = 0x8035ee24;
SECTIONS {
  .text.w3d_auto_8028dbf8 0x8028dbf8 : { *(.text.w3d_auto_8028dbf8) }
  .text.w3d_auto_8028e444 0x8028e444 : { *(.text.w3d_auto_8028e444) }
  .text.w3d_auto_8028e484 0x8028e484 : { *(.text.w3d_auto_8028e484) }
  .text.w3d_auto_8028e4f4 0x8028e4f4 : { *(.text.w3d_auto_8028e4f4) }
  .text.w3d_auto_8028e624 0x8028e624 : { *(.text.w3d_auto_8028e624) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; lbl_804AAABC = .;
    . = 0x1138; lbl_804ABBF4 = .;
    . = 0x61e8; lbl_804B0CA4 = .;
    . = 0x61f0; lbl_804B0CAC = .;
    . = 0x61f8; lbl_804B0CB4 = .;
    . = 0x6200; lbl_804B0CBC = .;
    . = 0x6208; lbl_804B0CC4 = .;
    . = 0x6210; lbl_804B0CCC = .;
    . = 0x6218; lbl_804B0CD4 = .;
    . = 0x6228; lbl_804B0CE4 = .;
    . = 0x6ccc; lbl_804B1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
