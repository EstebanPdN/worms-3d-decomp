/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8027a9e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8010A8E0 = 0x8010a8e0;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_802BD354 = 0x802bd354;
fn_802BD8CC = 0x802bd8cc;
fn_802BDD24 = 0x802bdd24;
SECTIONS {
  .text.w3d_auto_8027a9e4 0x8027a9e4 : { *(.text.w3d_auto_8027a9e4) }
  .text.w3d_auto_802b8418 0x802b8418 : { *(.text.w3d_auto_802b8418) }
  .text.w3d_auto_802bd3cc 0x802bd3cc : { *(.text.w3d_auto_802bd3cc) }
  .text.w3d_auto_802c4a70 0x802c4a70 : { *(.text.w3d_auto_802c4a70) }
  .text.w3d_auto_802e0f64 0x802e0f64 : { *(.text.w3d_auto_802e0f64) }
  .text.w3d_auto_8035a1dc 0x8035a1dc : { *(.text.w3d_auto_8035a1dc) }
  .sdata 0x804b0b34 (NOLOAD) : {
    . = 0x0; lbl_804B0B34 = .;
    . = 0xc20; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
