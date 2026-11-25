/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8003af00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800672A8 = 0x800672a8;
fn_800672B0 = 0x800672b0;
fn_800672B8 = 0x800672b8;
fn_8010A8E0 = 0x8010a8e0;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80164FC8 = 0x80164fc8;
SECTIONS {
  .text.w3d_auto_8003af00 0x8003af00 : { *(.text.w3d_auto_8003af00) }
  .text.w3d_auto_80066bc4 0x80066bc4 : { *(.text.w3d_auto_80066bc4) }
  .sdata 0x804ad12c (NOLOAD) : {
    . = 0x0; lbl_804AD12C = .;
    . = 0x4628; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
